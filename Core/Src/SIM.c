#include "stm32f1xx_hal.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "SIM.h"

extern UART_HandleTypeDef huart2;

char mobileNumber[] = "+84974671009";  // Enter the Mobile Number you want to send to
char mobileNumberStudent[]="+84383838116";
const char apn[]  = "v-internet";
const char server[] = "demo.thingsboard.io";
const int port = 80;
const char resource[] = "/api/v1/0vQ7YD1sUC7itsLGuuO1/telemetry";
const char token[] = "0vQ7YD1sUC7itsLGuuO1";
const uint32_t timeOut=10000;
uint8_t bufferModeInternet[100] = {0};
char content[100];
char ATcommand[100];
char httpRequest[512];
uint8_t ATisOK = 0;
uint8_t CGREGisOK = 0;
uint8_t CIPOPENisOK = 0;
uint8_t NETOPENisOK = 0;
uint32_t previousTick;

static bool Sim_CheckConnection(void)
{
	  bool retVal = true;
	  bool ATisOK2 = false;
	  uint8_t timeout = 5;
	  while((false == ATisOK2) && (0 < timeout))
	  {
	  		sprintf(ATcommand,"AT\r\n");
	  		HAL_UART_Transmit(&huart2,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	  		HAL_UART_Receive (&huart2, bufferModeInternet, 30, 100);
	  		HAL_Delay(1000);
	  		if(strstr((char *)bufferModeInternet,"OK")){
	  			ATisOK2 = true;
	  		}
	  		HAL_Delay(1000);
	  		memset(bufferModeInternet,0,sizeof(bufferModeInternet));
	  		timeout = timeout - 1;
	  }
	  if ((timeout == 0) || (ATisOK2 == false))
	  {
		  retVal = false;
	  }

	  return retVal;

}

void Sim_SendLocationDangerous(float latitude, float longitude)
{
	  Sim_CheckConnection();
	  sprintf(ATcommand,"AT+CMGF=1\r\n");
	  HAL_UART_Transmit(&huart2,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	  HAL_UART_Receive (&huart2, bufferModeInternet, 30, 100);
	  HAL_Delay(1000);
	  memset(bufferModeInternet,0,sizeof(bufferModeInternet));
	  sprintf(ATcommand,"AT+CMGS=\"%s\"\r\n",mobileNumber);
	  HAL_UART_Transmit(&huart2,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	  HAL_UART_Receive (&huart2, bufferModeInternet, 30, 100);
	  memset(bufferModeInternet,0,sizeof(bufferModeInternet));
	  HAL_Delay(100);
	  sprintf(ATcommand,"SOS:Canh bao nguy hiem:google.com/maps/place/%lf,%lf%c",latitude,longitude,0x1a);
	  HAL_UART_Transmit(&huart2,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	  HAL_UART_Receive (&huart2, bufferModeInternet, 50, 100);
	  memset(bufferModeInternet,0,sizeof(bufferModeInternet));
	  HAL_Delay(1000);
}

void Sim_SendLocationDangerousStudent(float latitude, float longitude)
{
	  Sim_CheckConnection();
	  sprintf(ATcommand,"AT+CMGF=1\r\n");
	  HAL_UART_Transmit(&huart2,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	  HAL_UART_Receive (&huart2, bufferModeInternet, 30, 100);
	  HAL_Delay(1000);
	  memset(bufferModeInternet,0,sizeof(bufferModeInternet));
	  sprintf(ATcommand,"AT+CMGS=\"%s\"\r\n",mobileNumberStudent);
	  HAL_UART_Transmit(&huart2,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	  HAL_UART_Receive (&huart2, bufferModeInternet, 30, 100);
	  memset(bufferModeInternet,0,sizeof(bufferModeInternet));
	  HAL_Delay(100);
	  sprintf(ATcommand,"SOS:Canh bao nguy hiem:google.com/maps/place/%lf,%lf%c",latitude,longitude,0x1a);
	  HAL_UART_Transmit(&huart2,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	  HAL_UART_Receive (&huart2, bufferModeInternet, 50, 100);
	  memset(bufferModeInternet,0,sizeof(bufferModeInternet));
	  HAL_Delay(1000);
}

void Sim_SendLocation(float latitude, float longitude)
{
	  Sim_CheckConnection();
	  sprintf(ATcommand,"AT+CMGF=1\r\n");
	  HAL_UART_Transmit(&huart2,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	  HAL_UART_Receive (&huart2, bufferModeInternet, 30, 100);
	  HAL_Delay(1000);
	  memset(bufferModeInternet,0,sizeof(bufferModeInternet));
	  sprintf(ATcommand,"AT+CMGS=\"%s\"\r\n",mobileNumber);
	  HAL_UART_Transmit(&huart2,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	  HAL_UART_Receive (&huart2, bufferModeInternet, 30, 100);
	  memset(bufferModeInternet,0,sizeof(bufferModeInternet));
	  HAL_Delay(100);
	  sprintf(ATcommand,"SOS:google.com/maps/place/%lf,%lf%c",latitude,longitude,0x1a);
	  HAL_UART_Transmit(&huart2,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	  HAL_UART_Receive (&huart2, bufferModeInternet, 50, 100);
	  memset(bufferModeInternet,0,sizeof(bufferModeInternet));
	  HAL_Delay(1000);
}

void Sim_SendLocationStudent(float latitude, float longitude)
{
	  Sim_CheckConnection();
	  sprintf(ATcommand,"AT+CMGF=1\r\n");
	  HAL_UART_Transmit(&huart2,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	  HAL_UART_Receive (&huart2, bufferModeInternet, 30, 100);
	  HAL_Delay(1000);
	  memset(bufferModeInternet,0,sizeof(bufferModeInternet));
	  sprintf(ATcommand,"AT+CMGS=\"%s\"\r\n",mobileNumberStudent);
	  HAL_UART_Transmit(&huart2,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	  HAL_UART_Receive (&huart2, bufferModeInternet, 30, 100);
	  memset(bufferModeInternet,0,sizeof(bufferModeInternet));
	  HAL_Delay(100);
	  sprintf(ATcommand,"SOS:google.com/maps/place/%lf,%lf%c",latitude,longitude,0x1a);
	  HAL_UART_Transmit(&huart2,(uint8_t *)ATcommand,strlen(ATcommand),1000);
	  HAL_UART_Receive (&huart2, bufferModeInternet, 50, 100);
	  memset(bufferModeInternet,0,sizeof(bufferModeInternet));
	  HAL_Delay(1000);
}

static void Sim_Transmit(char *cmd) {
  memset(bufferModeInternet, 0, sizeof(bufferModeInternet));
  HAL_UART_Transmit(&huart2, (uint8_t *)cmd, strlen(cmd), 1000);
  HAL_UART_Receive(&huart2, bufferModeInternet, 100, 1000);
}

void Sim_httpPost(float latitude, float longitude, uint8_t emergency)
{

  memset(ATcommand,0,sizeof(ATcommand));
  ATisOK = CGREGisOK = NETOPENisOK = CIPOPENisOK = 0;
  previousTick = HAL_GetTick();

  while(!ATisOK && HAL_GetTick() - previousTick < timeOut) {
    Sim_Transmit("AT\r\n");
    HAL_Delay(1000);
    if(strstr((char *)bufferModeInternet, "OK")) ATisOK = 1;
  }

  if(ATisOK) {
    previousTick = HAL_GetTick();
    while(!CGREGisOK && HAL_GetTick() - previousTick < timeOut) {
      Sim_Transmit("AT+CGREG?\r\n");
      if(strstr((char *)bufferModeInternet, "+CGREG: 0,1")) CGREGisOK = 1;
    }
  }

  if(ATisOK && CGREGisOK) {
    previousTick = HAL_GetTick();
    while(!NETOPENisOK && HAL_GetTick() - previousTick < timeOut) {
      Sim_Transmit("AT+NETCLOSE\r\n");
      sprintf(ATcommand, "AT+CGDCONT=1,\"IP\",\"%s\"\r\n", apn);
      Sim_Transmit(ATcommand);
      Sim_Transmit("AT+CIPMODE=0\r\n");
      Sim_Transmit("AT+CIPSENDMODE=0\r\n");
      Sim_Transmit("AT+CIPCCFG=10,0,0,0,1,0,75000\r\n");
      Sim_Transmit("AT+CIPTIMEOUT=75000,15000,15000\r\n");
      Sim_Transmit("AT+NETOPEN\r\n");
      Sim_Transmit("AT+NETOPEN?\r\n");
      if(strstr((char *)bufferModeInternet, "+NETOPEN: 1")) NETOPENisOK = 1;
    }
  }

  if(ATisOK && CGREGisOK && NETOPENisOK) {
    Sim_Transmit("AT+IPADDR\r\n");
    previousTick = HAL_GetTick();
    while(!CIPOPENisOK && HAL_GetTick() - previousTick < timeOut) {
      Sim_Transmit("AT+CIPCLOSE=0\r\n");
      sprintf(ATcommand, "AT+CIPOPEN=0,\"TCP\",\"%s\",%d\r\n", server, port);
      Sim_Transmit(ATcommand);
      HAL_Delay(1000);
      if(strstr((char *)bufferModeInternet, "+CIPOPEN: 0,0")) CIPOPENisOK = 1;
    }
  }

  if(ATisOK && CGREGisOK && CIPOPENisOK && NETOPENisOK) {
    // Tạo chuỗi JSON từ giá trị cảm biến
	  sprintf(content, "{\"latitude\": %.6f, \"longitude\": %.6f, \"emergency\": %d}", latitude, longitude,emergency);

    // Gửi request line
	  sprintf(httpRequest,
	              "POST /api/v1/%s/telemetry HTTP/1.1\r\n"
	              "Host: %s\r\n"
	              "Content-Type: application/json\r\n"
	              "Content-Length: %d\r\n"
	              "Connection: close\r\n"
	              "\r\n"
	              "%s\r\n",
	              token, server, strlen(content), content);

	  sprintf(ATcommand, "AT+CIPSEND=0,%d\r\n", strlen(httpRequest));
	  Sim_Transmit(ATcommand);

	  // Nếu được phép gửi (nhận ký tự '>')
	  if (strstr((char *)bufferModeInternet, ">")) {
		  Sim_Transmit(httpRequest);
	  }

	  HAL_Delay(2000); // Chờ phản hồi từ server (nếu cần, có thể thêm UART nhận phản hồi)

    // Đóng kết nối
    Sim_Transmit("AT+CIPCLOSE=0\r\n");
    Sim_Transmit("AT+NETCLOSE\r\n");
  }
}
