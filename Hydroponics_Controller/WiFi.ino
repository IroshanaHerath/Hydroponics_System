void update()
{
  WiFiClient client = server.available();
  if (client) 
  {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // output the value of each analog input pin
          
            
            client.print("Temperature : ");
            client.print(tempVal);
            client.print("C");
            client.println("<br />");
            
            client.print("Humidity : ");
            client.print(humid);
            client.print("%");
            client.println("<br />");
            
            client.print("CO2 Concentration : ");
            client.print(co2Val);
            client.print("ppm");
            client.println("<br />");
            
            client.print("pH Value : ");
            client.print(phValue);
            client.println("<br />");
            
            client.print("EC : ");
            client.print(ECcurrent);
            client.println("<br />");
            client.println("<br />");
            
            client.print("Remaining Volumes :");
            client.println("<br />");
            
            for (int bottle = 0; bottle < 6; bottle++) 
            {
              client.print("Nut. Bottle ");
              client.print(bottle);
              client.print(". - ");
              client.print(currentNut[bottle]);
              client.println("<br />");
            }
          
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);

    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }

}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
