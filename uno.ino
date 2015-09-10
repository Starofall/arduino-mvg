//states
//0 = mvg
int state = 0;

//network timer
int networkTimer = 0;
//state timer
int stateTimer = 0;

extern int uBahnAvailable;

void setup() {
    randomSeed(analogRead(0));
    Serial.begin(9600);
    setupNetwork();
    setupUI();
}

void loop() { //passed every 100ms
    stateTimer++;
    networkTimer++;

    if(networkTimer>100) {
        networkTimer = 0;
    
        setUpdating();
        drawUpdate();
    
        updateData();  
        unsetUpdating();      
    }
    clearMatrix();
    if(uBahnAvailable){
      drawMVGState();
    }
    drawUpdate();
    delay(100);
}
