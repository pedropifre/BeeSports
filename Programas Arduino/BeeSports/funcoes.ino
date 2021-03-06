//##################### FUNÇÕES ####################
const char* ssid = "Virus";
const char* password = "ric12345";

static void iniciaSerial()
{
  Serial.println("Booting in 115200");
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println("Serial Iniciado com Sucesso.");
}

void iniciaWifi() {
  WiFi.mode(WIFI_STA);
  delay(5000);
  WiFi.begin(ssid, password);
  //Serial.println("\nConnecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    Serial.println("");
    delay(1000);
  }
  Serial.print("Endereco IP: ");
  Serial.println(WiFi.localIP());
}

static void iniciaTempo() {
  time_t epochTime;
  int timezone = -3;
  int dst = 0;
  configTime(timezone * 3600, dst, "pool.ntp.org", "time.nist.gov");
  Serial.println("\nConectando aos sites de Tempo");
  while (true) {
    epochTime = time(NULL);

    //if (epochTime < MIN_EPOCH) {
    //  Serial.println("Fetching NTP epoch time failed! Waiting 2 seconds to retry.");
    //delay(2000);
    //} else {
    Serial.print("Fetched NTP epoch time is: ");
    Serial.println(epochTime);
    //  break;
  }
Serial.println("Conectado ao tempo!");
}
//#################################################################################
