#include <IRremote.h>


#define RECEIVER_PIN 2


IRrecv receiver(RECEIVER_PIN);
IRData * res;


void setup() {
  Serial.begin(115200);
  setLEDFeedback(0, true); // builtin led
  receiver.enableIRIn();
}

char * recvIRDataToString(decode_type_t type) {
  switch (type) {
    case UNKNOWN:
      return "UNKNOWN";
      break;
    case PULSE_DISTANCE:
      return "PULSE_DISTANCE";
      break;
    case PULSE_WIDTH:
      return "PULSE_WIDTH";
      break;
    case DENON:
      return "DENON";
      break;
    case DISH:
      return "DISH";
      break;
    case JVC:
      return "JVC";
      break;
    case LG:
      return "LG";
      break;
    case NEC:
      return "NEC";
      break;
    case PANASONIC:
      return "PANASONIC";
      break;
    case KASEIKYO:
      return "KASEIKYO";
      break;
    case KASEIKYO_JVC:
      return "KASEIKYO_JVC";
      break;
    case KASEIKYO_DENON:
      return "KASEIKYO_DENON";
      break;
    case KASEIKYO_SHARP:
      return "KASEIKYO_SHARP";
      break;
    case KASEIKYO_MITSUBISHI:
      return "KASEIKYO_MITSUBISHI";
      break;
    case RC5:
      return "RC5";
      break;
    case RC6:
      return "RC6";
      break;
    case SAMSUNG:
      return "SAMSUNG";
      break;
    case SHARP:
      return "SHARP";
      break;
    case SONY:
      return "SONY";
      break;
    case ONKYO:
      return "ONKYO";
      break;
    case APPLE:
      return "APPLE";
      break;
    case BOSEWAVE:
      return "BOSEWAVE";
      break;
    case LEGO_PF:
      return "LEGO_PF";
      break;
    case MAGIQUEST:
      return "MAGIQUEST";
      break;
    case WHYNTER:
      return "WHYNTER";
      break;
    default:
      return "Unrecognised UNKNOWN";
      break;
  }
}

void loop() {
  if (receiver.decode()) {
    res = receiver.read();
    Serial.println(res->decodedRawData, HEX);
    Serial.println(recvIRDataToString(res->protocol));
    Serial.println("--------------------");
    receiver.resume();
  }
}