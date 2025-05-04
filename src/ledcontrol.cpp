#include <FastLED.h>

#define frontLedsNumber 16
#define backLeftLedsNumber 3
#define backRightLedsNumber 3

CRGB frontLeds[18];
CRGB backLeftLeds[3];
CRGB backRightLeds[3];
CRGB currentColor = CRGB(242, 158, 12); // Initialfarbe

int ch0, ch1, ch4, ch5, ch6, ch7, ch8, ch9 = 0;
int ch6State, ch7State, ch8State, ch9State = 1000;
int ledstate, ledConnecting = 0;
int pot, out1, out2 = 0;
int i = 0;
int k = 0;
int k2 = 0;
int j = 0;
int r = 1;
int t = 0;
int i1 = 0;
int i1State = 0;

unsigned long previousMillis = 0;
unsigned long interval = 50;
unsigned long interval2 = 300;

void initled()
{
    FastLED.addLeds<WS2812, 24, GRB>(frontLeds, frontLedsNumber);
    FastLED.addLeds<WS2812, 23, GRB>(backLeftLeds, backLeftLedsNumber);
    FastLED.addLeds<WS2812, 22, GRB>(backRightLeds, backRightLedsNumber);
    ledstate = 0;

    for (int i = 0; i <= frontLedsNumber; i++)
    {
        frontLeds[i] = CRGB(250, 5, 5);
    }
    for (int i = 0; i <= backLeftLedsNumber; i++)
    {
        backLeftLeds[i] = CRGB(250, 5, 5);
        backRightLeds[i] = CRGB(250, 5, 5);
    }
    FastLED.show();
}

void ledDevConnecting()
{
    ledConnecting = !ledConnecting;
    currentColor = ledConnecting ? CRGB(45, 102, 194) : CRGB(245, 245, 245); // Grün oder Orange

    for (int i = 0; i <= frontLedsNumber; i++)
    {
        frontLeds[i] = currentColor;
    }
    for (int i = 0; i <= backLeftLedsNumber; i++)
    {
        backLeftLeds[i] = currentColor;
        backRightLeds[i] = currentColor;
    }
    FastLED.show();
}

void ledBatEmpty()
{
    currentColor = CRGB(115, 37, 179); // violett

    for (int i = 0; i <= frontLedsNumber; i++)
    {
        frontLeds[i] = currentColor;
    }
    for (int i = 0; i <= backLeftLedsNumber; i++)
    {
        backLeftLeds[i] = currentColor;
        backRightLeds[i] = currentColor;
    }
    FastLED.show();
}

void ledcontrol(int analogValue6)
{
    //===== LIGHTS Control ===
    if (analogValue6 == 1)
    {
        ledstate += 1;
    }
    if (ledstate > 5)
    {
        ledstate = 0;
    }
    if (ledstate < 0)
    {
        ledstate = 0;
    }
    // Serial.print("ledstatus: "); Serial.print(ledstate); Serial.print(" "); Serial.println(analogValue6);

    // Front and back lights LEDs control
    if (ledstate == 0)
    {
        for (int i = 0; i <= frontLedsNumber; i++)
        {
            frontLeds[i] = CRGB(5, 250, 30);
        }
        for (int i = 0; i <= backLeftLedsNumber; i++)
        {
            backLeftLeds[i] = CRGB(5, 250, 30);
            backRightLeds[i] = CRGB(5, 250, 30);
        }
        FastLED.show();
    }

    if (ledstate == 1)
    {
        frontLeds[0] = CRGB(255, 255, 255);
        frontLeds[1] = CRGB(255, 255, 255);
        frontLeds[2] = CRGB(255, 255, 255);
        frontLeds[3] = CRGB(255, 255, 255);
        frontLeds[4] = CRGB(255, 255, 255);
        frontLeds[5] = CRGB(0, 0, 0);
        frontLeds[6] = CRGB(0, 0, 0);
        frontLeds[7] = CRGB(0, 0, 0);
        frontLeds[8] = CRGB(0, 0, 0);
        frontLeds[9] = CRGB(0, 0, 0);
        frontLeds[10] = CRGB(0, 0, 0);
        frontLeds[11] = CRGB(255, 255, 255);
        frontLeds[12] = CRGB(255, 255, 255);
        frontLeds[13] = CRGB(255, 255, 255);
        frontLeds[14] = CRGB(255, 255, 255);
        frontLeds[15] = CRGB(255, 255, 255);
        backLeftLeds[0] = CRGB(255, 0, 0);
        backLeftLeds[1] = CRGB(255, 0, 0);
        backLeftLeds[2] = CRGB(255, 0, 0);
        backRightLeds[0] = CRGB(255, 0, 0);
        backRightLeds[1] = CRGB(255, 0, 0);
        backRightLeds[2] = CRGB(255, 0, 0);
        FastLED.show();
    }
    if (ch9 != ch9State)
    {
        if (ch9 == 1000)
        {
            FastLED.clear();
        }
        ch9State = ch9;
        FastLED.show();
    }

    // Front and back lights LEDs control
    if (ledstate == 2)
    {
        frontLeds[0] = CRGB(255, 255, 255);
        frontLeds[1] = CRGB(255, 255, 255);
        frontLeds[2] = CRGB(255, 255, 255);
        frontLeds[3] = CRGB(255, 255, 255);
        frontLeds[4] = CRGB(255, 255, 255);
        frontLeds[5] = CRGB(255, 255, 255);
        frontLeds[6] = CRGB(255, 255, 255);
        frontLeds[7] = CRGB(255, 255, 255);
        frontLeds[8] = CRGB(255, 255, 255);
        frontLeds[9] = CRGB(255, 255, 255);
        frontLeds[10] = CRGB(255, 255, 255);
        frontLeds[11] = CRGB(255, 255, 255);
        frontLeds[12] = CRGB(255, 255, 255);
        frontLeds[13] = CRGB(255, 255, 255);
        frontLeds[14] = CRGB(255, 255, 255);
        frontLeds[15] = CRGB(255, 255, 255);
        backLeftLeds[0] = CRGB(255, 0, 0);
        backLeftLeds[1] = CRGB(255, 0, 0);
        backLeftLeds[2] = CRGB(255, 0, 0);
        backRightLeds[0] = CRGB(255, 0, 0);
        backRightLeds[1] = CRGB(255, 0, 0);
        backRightLeds[2] = CRGB(255, 0, 0);
        FastLED.show();
    }
    if (ledstate == 3)
    {
        frontLeds[0] = CRGB(255, 255, 255);
        frontLeds[1] = CRGB(255, 255, 255);
        frontLeds[2] = CRGB(255, 255, 255);
        frontLeds[3] = CRGB(255, 255, 255);
        frontLeds[4] = CRGB(255, 255, 255);
        frontLeds[5] = CRGB(255, 255, 255);
        frontLeds[6] = CRGB(255, 255, 255);
        frontLeds[7] = CRGB(255, 255, 255);
        frontLeds[8] = CRGB(255, 255, 255);
        frontLeds[9] = CRGB(255, 255, 255);
        frontLeds[10] = CRGB(255, 255, 255);
        frontLeds[11] = CRGB(255, 255, 255);
        frontLeds[12] = CRGB(255, 255, 255);
        frontLeds[13] = CRGB(255, 255, 255);
        frontLeds[14] = CRGB(255, 255, 255);
        frontLeds[15] = CRGB(255, 255, 255);
        backLeftLeds[0] = CRGB(255, 0, 0);
        backLeftLeds[1] = CRGB(255, 0, 0);
        backLeftLeds[2] = CRGB(255, 0, 0);
        backRightLeds[0] = CRGB(255, 0, 0);
        backRightLeds[1] = CRGB(255, 0, 0);
        backRightLeds[2] = CRGB(255, 0, 0);
        FastLED.show();

        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis > 40)
        {

            if (i1 == 0)
            {
                i1 = 1;
            }
            else if (i1 == 1)
            {
                i1 = 0;
            }
            previousMillis = currentMillis;
        }

        if (i1 == 0)
        {
            FastLED.clear();
            // FastLED.show ();
        }
        if (i1 == 1)
        {
            // FastLED.show ();
        }
        if (i1 != i1State)
        {
            i1State = i1;
            FastLED.show();
        }
    }

    if (ch8 != ch8State)
    {
        if (ch8 == 1000)
        {
            FastLED.clear();
        }
        ch8State = ch8;
        FastLED.show();
    }

    // Serial.print("   i1:");
    // Serial.println(i1);
    // Serial.print("   ch8:");
    // Serial.print(ch8);

    // ======= Police strobe =======

    if (ledstate == 4)
    {

        if (r == 4)
        {
            interval = 110;
        }
        else if (r == 6)
        {
            interval = 120;
        }
        else if (r == 8)
        {
            interval = 5;
        }
        else
        {
            interval = 60;
        }
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis > interval)
        {

            if (i1 == 0)
            {
                i1 = 1;
            }
            else if (i1 == 1)
            {
                i1 = 0;
                k++;
            }
            previousMillis = currentMillis;
        }

        if (i1 == 0)
        {
            if (r == 4)
            {
                // do nothing
            }
            else if (r == 6)
            {
                // do nothing
            }
            else if (r == 8)
            {
                // do nothing
            }
            else
            {
                FastLED.clear();
            }
        }
        else if (i1 == 1)
        {
            switch (r)
            {
            case 1:
                switch (k)
                {
                case 1:
                    frontLeds[0] = CRGB(255, 0, 0);
                    frontLeds[1] = CRGB(255, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(255, 0, 0);
                    frontLeds[5] = CRGB(255, 0, 0);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);

                    // FastLED.show();
                    break;
                case 2:
                    frontLeds[0] = CRGB(255, 0, 0);
                    frontLeds[1] = CRGB(255, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(255, 0, 0);
                    frontLeds[5] = CRGB(255, 0, 0);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    // FastLED.show();
                    break;
                case 3:
                    frontLeds[0] = CRGB(255, 0, 0);
                    frontLeds[1] = CRGB(255, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(255, 0, 0);
                    frontLeds[5] = CRGB(255, 0, 0);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    // FastLED.show();
                    break;
                case 4:
                    frontLeds[10] = CRGB(0, 0, 255);
                    frontLeds[11] = CRGB(0, 0, 255);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);

                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    // FastLED.show();
                    break;
                case 5:
                    frontLeds[10] = CRGB(0, 0, 255);
                    frontLeds[11] = CRGB(0, 0, 255);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);

                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    // FastLED.show();
                    break;
                case 6:
                    frontLeds[10] = CRGB(0, 0, 255);
                    frontLeds[11] = CRGB(0, 0, 255);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);

                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    // FastLED.show();
                    j++;
                    if (j < 3)
                    {
                        k = 0;
                    }
                    break;
                case 7:
                    r = 2;
                    k = 1;
                    frontLeds[0] = CRGB(255, 0, 0);
                    frontLeds[1] = CRGB(255, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(255, 0, 0);
                    frontLeds[5] = CRGB(255, 0, 0);
                    frontLeds[6] = CRGB(255, 255, 255);
                    frontLeds[7] = CRGB(255, 255, 255);
                    frontLeds[8] = CRGB(255, 255, 255);
                    frontLeds[9] = CRGB(255, 255, 255);
                    frontLeds[10] = CRGB(0, 0, 255);
                    frontLeds[11] = CRGB(0, 0, 255);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);
                    break;
                }

                break;

            case 2:
                frontLeds[0] = CRGB(255, 0, 0);
                frontLeds[1] = CRGB(255, 0, 0);
                frontLeds[2] = CRGB(255, 0, 0);
                frontLeds[3] = CRGB(255, 0, 0);
                frontLeds[4] = CRGB(255, 0, 0);
                frontLeds[5] = CRGB(255, 0, 0);
                frontLeds[6] = CRGB(255, 255, 255);
                frontLeds[7] = CRGB(255, 255, 255);
                frontLeds[8] = CRGB(255, 255, 255);
                frontLeds[9] = CRGB(255, 255, 255);
                frontLeds[10] = CRGB(0, 0, 255);
                frontLeds[11] = CRGB(0, 0, 255);
                frontLeds[12] = CRGB(0, 0, 255);
                frontLeds[13] = CRGB(0, 0, 255);
                frontLeds[14] = CRGB(0, 0, 255);
                frontLeds[15] = CRGB(0, 0, 255);

                backLeftLeds[0] = CRGB(255, 0, 0);
                backLeftLeds[1] = CRGB(255, 0, 0);
                backLeftLeds[2] = CRGB(255, 0, 0);
                backRightLeds[0] = CRGB(0, 0, 255);
                backRightLeds[1] = CRGB(0, 0, 255);
                backRightLeds[2] = CRGB(0, 0, 255);
                if (k == 10)
                {
                    k = 1;
                    r = 3;
                    j = 0;
                }
                break;
            case 3:
                switch (k)
                {
                case 1:
                    frontLeds[0] = CRGB(255, 0, 0);
                    frontLeds[1] = CRGB(255, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(255, 0, 0);
                    frontLeds[5] = CRGB(255, 0, 0);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    // FastLED.show();
                    break;
                case 2:
                    frontLeds[0] = CRGB(255, 0, 0);
                    frontLeds[1] = CRGB(255, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(255, 0, 0);
                    frontLeds[5] = CRGB(255, 0, 0);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    // FastLED.show();
                    break;
                case 3:
                    frontLeds[0] = CRGB(255, 0, 0);
                    frontLeds[1] = CRGB(255, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(255, 0, 0);
                    frontLeds[5] = CRGB(255, 0, 0);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    // FastLED.show();
                    break;
                case 4:
                    frontLeds[10] = CRGB(0, 0, 255);
                    frontLeds[11] = CRGB(0, 0, 255);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    // FastLED.show();
                    break;
                case 5:
                    frontLeds[10] = CRGB(0, 0, 255);
                    frontLeds[11] = CRGB(0, 0, 255);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    // FastLED.show();
                    break;
                case 6:
                    frontLeds[10] = CRGB(0, 0, 255);
                    frontLeds[11] = CRGB(0, 0, 255);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    // FastLED.show();

                    j++;
                    if (j < 2)
                    {
                        k = 0;
                        // r = 1;
                        // j = 0;
                    }
                    break;
                case 7:
                    r = 4;
                    k = 0;
                    k2 = 0;
                    j = 0;
                    frontLeds[0] = CRGB(255, 0, 0);
                    frontLeds[1] = CRGB(255, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(0, 0, 0);
                    frontLeds[5] = CRGB(0, 0, 0);
                    frontLeds[6] = CRGB(0, 0, 0);
                    frontLeds[7] = CRGB(0, 0, 0);
                    frontLeds[8] = CRGB(0, 0, 0);
                    frontLeds[9] = CRGB(0, 0, 0);
                    frontLeds[10] = CRGB(0, 0, 0);
                    frontLeds[11] = CRGB(0, 0, 0);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);
                    break;
                }
                break;
            case 4: // 4th
                //---------
                switch (k)
                {
                case 1:
                    frontLeds[0] = CRGB(0, 0, 0);
                    frontLeds[1] = CRGB(0, 0, 0);
                    frontLeds[2] = CRGB(0, 0, 0);
                    frontLeds[3] = CRGB(0, 0, 0);
                    frontLeds[4] = CRGB(255, 0, 0);
                    frontLeds[5] = CRGB(255, 0, 0);
                    frontLeds[6] = CRGB(255, 0, 0);
                    frontLeds[7] = CRGB(255, 0, 0);
                    frontLeds[8] = CRGB(0, 0, 255);
                    frontLeds[9] = CRGB(0, 0, 255);
                    frontLeds[10] = CRGB(0, 0, 255);
                    frontLeds[11] = CRGB(0, 0, 255);
                    frontLeds[12] = CRGB(0, 0, 0);
                    frontLeds[13] = CRGB(0, 0, 0);
                    frontLeds[14] = CRGB(0, 0, 0);
                    frontLeds[15] = CRGB(0, 0, 0);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    break;
                case 2:
                    frontLeds[0] = CRGB(255, 0, 0);
                    frontLeds[1] = CRGB(255, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(0, 0, 0);
                    frontLeds[5] = CRGB(0, 0, 0);
                    frontLeds[6] = CRGB(0, 0, 0);
                    frontLeds[7] = CRGB(0, 0, 0);
                    frontLeds[8] = CRGB(0, 0, 0);
                    frontLeds[9] = CRGB(0, 0, 0);
                    frontLeds[10] = CRGB(0, 0, 0);
                    frontLeds[11] = CRGB(0, 0, 0);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);

                    backLeftLeds[0] = CRGB(0, 0, 255);
                    backLeftLeds[1] = CRGB(0, 0, 255);
                    backLeftLeds[2] = CRGB(0, 0, 255);
                    backRightLeds[0] = CRGB(255, 0, 0);
                    backRightLeds[1] = CRGB(255, 0, 0);
                    backRightLeds[2] = CRGB(255, 0, 0);
                    j++;
                    if (j < 8)
                    {
                        k = 0;
                    }
                    break;
                case 3:
                    r = 5;
                    k = 1;
                    j = 0;
                    break;
                }

                break; //--------- End of 4th light show

            case 5: // ---- 5th light show
                switch (k)
                {
                case 1:
                    frontLeds[6] = CRGB(255, 255, 255);
                    frontLeds[7] = CRGB(255, 255, 255);
                    frontLeds[8] = CRGB(255, 255, 255);
                    frontLeds[9] = CRGB(255, 255, 255);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(255, 0, 0);
                    backRightLeds[1] = CRGB(255, 0, 0);
                    backRightLeds[2] = CRGB(255, 0, 0);
                    break;
                case 2:
                    frontLeds[6] = CRGB(255, 255, 255);
                    frontLeds[7] = CRGB(255, 255, 255);
                    frontLeds[8] = CRGB(255, 255, 255);
                    frontLeds[9] = CRGB(255, 255, 255);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(255, 0, 0);
                    backRightLeds[1] = CRGB(255, 0, 0);
                    backRightLeds[2] = CRGB(255, 0, 0);
                    break;
                case 3:
                    frontLeds[6] = CRGB(255, 255, 255);
                    frontLeds[7] = CRGB(255, 255, 255);
                    frontLeds[8] = CRGB(255, 255, 255);
                    frontLeds[9] = CRGB(255, 255, 255);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(255, 0, 0);
                    backRightLeds[1] = CRGB(255, 0, 0);
                    backRightLeds[2] = CRGB(255, 0, 0);
                    break;
                case 4:
                    frontLeds[6] = CRGB(255, 255, 255);
                    frontLeds[7] = CRGB(255, 255, 255);
                    frontLeds[8] = CRGB(255, 255, 255);
                    frontLeds[9] = CRGB(255, 255, 255);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(255, 0, 0);
                    backRightLeds[1] = CRGB(255, 0, 0);
                    backRightLeds[2] = CRGB(255, 0, 0);
                    break;
                case 5:
                    frontLeds[6] = CRGB(255, 255, 255);
                    frontLeds[7] = CRGB(255, 255, 255);
                    frontLeds[8] = CRGB(255, 255, 255);
                    frontLeds[9] = CRGB(255, 255, 255);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(255, 0, 0);
                    backRightLeds[1] = CRGB(255, 0, 0);
                    backRightLeds[2] = CRGB(255, 0, 0);
                    break;
                case 6:
                    frontLeds[6] = CRGB(255, 255, 255);
                    frontLeds[7] = CRGB(255, 255, 255);
                    frontLeds[8] = CRGB(255, 255, 255);
                    frontLeds[9] = CRGB(255, 255, 255);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(255, 0, 0);
                    backRightLeds[1] = CRGB(255, 0, 0);
                    backRightLeds[2] = CRGB(255, 0, 0);
                    break;
                case 7:
                    r = 6;
                    k = 1;
                    j = 0;
                    frontLeds[0] = CRGB(255, 0, 0);
                    frontLeds[1] = CRGB(255, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(0, 0, 0);
                    frontLeds[5] = CRGB(0, 0, 0);
                    frontLeds[6] = CRGB(255, 255, 255);
                    frontLeds[7] = CRGB(255, 255, 255);
                    frontLeds[8] = CRGB(255, 255, 255);
                    frontLeds[9] = CRGB(255, 255, 255);
                    frontLeds[10] = CRGB(0, 0, 0);
                    frontLeds[11] = CRGB(0, 0, 0);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);
                    break;
                }
                break; //--------- End of 5th light show

            case 6: // ---- 6th light show
                switch (k)
                {
                case 1:
                    frontLeds[0] = CRGB(0, 0, 0);
                    frontLeds[1] = CRGB(0, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(255, 0, 0);
                    frontLeds[5] = CRGB(255, 0, 0);
                    frontLeds[6] = CRGB(0, 0, 0);
                    frontLeds[7] = CRGB(0, 0, 0);
                    frontLeds[8] = CRGB(0, 0, 0);
                    frontLeds[9] = CRGB(0, 0, 0);
                    frontLeds[10] = CRGB(0, 0, 255);
                    frontLeds[11] = CRGB(0, 0, 255);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 0);
                    frontLeds[15] = CRGB(0, 0, 0);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    break;
                case 2:
                    frontLeds[0] = CRGB(255, 0, 0);
                    frontLeds[1] = CRGB(255, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(0, 0, 0);
                    frontLeds[5] = CRGB(0, 0, 0);
                    frontLeds[6] = CRGB(255, 255, 255);
                    frontLeds[7] = CRGB(255, 255, 255);
                    frontLeds[8] = CRGB(255, 255, 255);
                    frontLeds[9] = CRGB(255, 255, 255);
                    frontLeds[10] = CRGB(0, 0, 0);
                    frontLeds[11] = CRGB(0, 0, 0);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);

                    backLeftLeds[0] = CRGB(0, 0, 255);
                    backLeftLeds[1] = CRGB(0, 0, 255);
                    backLeftLeds[2] = CRGB(0, 0, 255);
                    backRightLeds[0] = CRGB(255, 0, 0);
                    backRightLeds[1] = CRGB(255, 0, 0);
                    backRightLeds[2] = CRGB(255, 0, 0);
                    j++;
                    if (j < 8)
                    {
                        k = 0;
                    }
                    break;
                case 3:
                    r = 7;
                    k = 1;
                    j = 0;
                    frontLeds[0] = CRGB(0, 0, 255);
                    frontLeds[1] = CRGB(0, 0, 255);
                    frontLeds[2] = CRGB(0, 0, 255);
                    frontLeds[3] = CRGB(0, 0, 255);
                    frontLeds[4] = CRGB(0, 0, 255);
                    frontLeds[5] = CRGB(0, 0, 255);
                    frontLeds[6] = CRGB(0, 0, 255);
                    frontLeds[7] = CRGB(0, 0, 255);
                    frontLeds[8] = CRGB(0, 0, 255);
                    frontLeds[9] = CRGB(0, 0, 255);
                    frontLeds[10] = CRGB(0, 0, 255);
                    frontLeds[11] = CRGB(0, 0, 255);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);
                    break;
                }
                break; //--------- End of 6th light show

            case 7: // ---- 7th light show
                switch (k)
                {
                case 1:
                    frontLeds[0] = CRGB(255, 0, 0);
                    frontLeds[1] = CRGB(255, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(255, 0, 0);
                    frontLeds[5] = CRGB(255, 0, 0);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    // FastLED.show();
                    break;
                case 2:
                    frontLeds[0] = CRGB(255, 0, 0);
                    frontLeds[1] = CRGB(255, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(255, 0, 0);
                    frontLeds[5] = CRGB(255, 0, 0);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    // FastLED.show();
                    break;
                case 3:
                    frontLeds[0] = CRGB(255, 0, 0);
                    frontLeds[1] = CRGB(255, 0, 0);
                    frontLeds[2] = CRGB(255, 0, 0);
                    frontLeds[3] = CRGB(255, 0, 0);
                    frontLeds[4] = CRGB(255, 0, 0);
                    frontLeds[5] = CRGB(255, 0, 0);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    // FastLED.show();
                    break;
                case 4:
                    frontLeds[10] = CRGB(0, 0, 255);
                    frontLeds[11] = CRGB(0, 0, 255);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);

                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    // FastLED.show();
                    break;
                case 5:
                    frontLeds[10] = CRGB(0, 0, 255);
                    frontLeds[11] = CRGB(0, 0, 255);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);

                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    // FastLED.show();
                    break;
                case 6:
                    frontLeds[10] = CRGB(0, 0, 255);
                    frontLeds[11] = CRGB(0, 0, 255);
                    frontLeds[12] = CRGB(0, 0, 255);
                    frontLeds[13] = CRGB(0, 0, 255);
                    frontLeds[14] = CRGB(0, 0, 255);
                    frontLeds[15] = CRGB(0, 0, 255);

                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    // FastLED.show();

                    j++;
                    if (j < 2)
                    {
                        k = 0;
                        // r = 1;
                        // j = 0;
                    }
                    break;
                case 7:
                    r = 8;
                    k = 0;
                    k2 = 0;
                    j = 0;
                    break;
                }
                break; //--------- End of 7th light show

            case 8: // ---- 8th light show
                if (k < 16)
                {
                    frontLeds[k] = CRGB(255, 0, 0);

                    backLeftLeds[0] = CRGB(255, 0, 0);
                    backLeftLeds[1] = CRGB(255, 0, 0);
                    backLeftLeds[2] = CRGB(255, 0, 0);
                    backRightLeds[0] = CRGB(0, 0, 255);
                    backRightLeds[1] = CRGB(0, 0, 255);
                    backRightLeds[2] = CRGB(0, 0, 255);
                    k2 = k;
                }
                if (k >= 16)
                {

                    frontLeds[k2] = CRGB(0, 0, 255);

                    backLeftLeds[0] = CRGB(0, 0, 0);
                    backLeftLeds[1] = CRGB(0, 0, 0);
                    backLeftLeds[2] = CRGB(0, 0, 0);
                    backRightLeds[0] = CRGB(0, 0, 0);
                    backRightLeds[1] = CRGB(0, 0, 0);
                    backRightLeds[2] = CRGB(0, 0, 0);
                    k2 = (16 - (k - 16));
                }
                if (k2 == -1)
                {
                    k = 0;
                    j++;
                    if (j >= 10)
                    {
                        j = 0;
                        r = 1;
                    }
                }

                break; //--------- End of 8th light show
            }
        }

        if (i1 != i1State)
        {
            i1State = i1;
            FastLED.show();
        }
    }

    // ======= LED Off =============
    if (ledstate == 5)
    {
        for (int i = 0; i <= frontLedsNumber; i++)
        {
            frontLeds[i] = CRGB(0, 0, 0);
        }
        for (int i = 0; i <= backLeftLedsNumber; i++)
        {
            backLeftLeds[i] = CRGB(0, 0, 0);
            backRightLeds[i] = CRGB(0, 0, 0);
        }
        FastLED.show();
    }
}