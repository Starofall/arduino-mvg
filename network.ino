#include <SPI.h>
#include <Ethernet.h>
#include <TextFinder.h>
#include <utility/w5100.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
char mvgServer[] = "www.mvg-live.de";


EthernetClient client;
TextFinder finder( client , 1 );

//Default values
int uBahn = 88;
int temp = 88;
int timeHour = 88;
int liftAlarm = 0;
int uBahnAvailable = 0;

void updateData() {
    client.stop();
    Serial.println("connecting... to MVG");
    if (client.connect(mvgServer, 80)) {
      client.println("GET /ims/dfiStaticAuswahl.svc?haltestelle=$INSERTSTATIONNAME$&ubahn=checked&bus=checked&tram=checked&sbahn=checked HTTP/1.1");
      client.println("Host: www.mvg-live.de");
      client.println("User-Agent: arduino-ethernet");
      client.println("Connection: close");
      client.println();

      //Parse Time
      finder.find("serverTimeColumn\">");
      timeHour = finder.getValue(); // get numeric value
      Serial.println("TIME:");
      Serial.println(timeHour);

      //Parse Time of UBahn
      if(finder.findUntil("$INSERTDIRECTION$","Impressum")){
        if(finder.find("inMinColumn\">")){
              uBahn = finder.getValue(); // get numeric value
              uBahnAvailable = 1;
          }
      } else{
        uBahnAvailable = 0;
      }
    } else {
      uBahn = 88;
      Serial.println("connection failed to mvg server");
    }
}

void setupNetwork() {
    Ethernet.begin(mac);
    W5100.setRetransmissionTime(0x07D0);
    W5100.setRetransmissionCount(3);
    delay(2000);
}
