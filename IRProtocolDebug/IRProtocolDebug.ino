#include <IRremote.h>

//#define DEBUG_MSB_IRREMOTE2 // in order for NEC, Panasonic, Sony, Samsung and JVC to be in non-standard MSB representation


#define RECEIVER_PIN 2


IRrecv receiver(RECEIVER_PIN);


void setup() {
  Serial.begin(115200);
  setLEDFeedback(0, true); // builtin led
  receiver.enableIRIn();
}

const char * recvIRDataProtocolToString(decode_type_t type) {
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

void print(uint32_t data, decode_type_t protocol) {
  Serial.println(data, HEX);
  Serial.println(recvIRDataProtocolToString(protocol));
  Serial.println("--------------------");
}

uint32_t reverseBitsSignificance(uint32_t data){
  uint8_t totalBits = sizeof(data) * 8;
  uint32_t reverse = 0, i, temp;

  for (i = 0; i < totalBits; i++) {
    temp = (data & (1 << i));
    if (temp)
      reverse |= (1 << ((totalBits - 1) - i));
  }

  return reverse;
}

void loop() {
#ifdef DEBUG_LSB_IRREMOTE2
  decode_results res;
  if (receiver.decode(&results)) {
    print(res.value, res.decode_type);
#endif
#ifndef DEBUG_LSB_IRREMOTE2
  if (receiver.decode()) {
    IRData * res = receiver.read();
    print(res->decodedRawData, res->protocol);
#endif
    receiver.resume();
  }
}