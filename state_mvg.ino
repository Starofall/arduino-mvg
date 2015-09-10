extern int state;
extern int stateTimer;
extern int uBahn;
extern int liftAlarm;
extern int timeHour;

void runMVGState() {
    clearMatrix();
    if (stateTimer > 90) {
        stateTimer = 0;
        state = 1;
    }
    drawMVGState();
}


void drawMVGState() {
    if (uBahn < 10) {
        if (liftAlarm == 1) {//we only show lift warnings if ubahn is under 10 minutes
            drawLiftMiddle(255, 0, 0);
        }
        int colorR = 0;
        int colorG = 0;
        switch (uBahn) {
            case 0:
                colorG = 255;
                colorR = 0;
                break;
            case 1:
                colorG = 255;
                colorR = 0;
                break;
            case 2:
                colorG = 255;
                colorR = 0;
                break;
            case 3:
                colorG = 0;
                colorR = 255;
                break;
            case 4:
                colorG = 55;
                colorR = 200;
                break;
            case 5:
                colorG = 100;
                colorR = 140;
                break;
            case 6:
                colorG = 215;
                colorR = 60;
                break;
            case 7:
                colorG = 235;
                colorR = 20;
                break;
            case 8:
                colorG = 255;
                colorR = 0;
                break;
            case 9:
                colorG = 255;
                colorR = 0;
                break;
        }
        drawIntegerRight(uBahn, colorR, colorG, 0);
    } else {//>10 Min
        if (timeHour > 5 && timeHour < 23) {//after 5 and before 23 more than 10 minutes -> NOT GOOD
            drawIntegerMiddle(get10Value(uBahn), 255, 0, 0);
            drawIntegerRight(get01Value(uBahn), 255, 0, 0);
        } else {
            drawIntegerMiddle(get10Value(uBahn), 0, 255, 0);
            drawIntegerRight(get01Value(uBahn), 0, 255, 0);
        }
    }
}