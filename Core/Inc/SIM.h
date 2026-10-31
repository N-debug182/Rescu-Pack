#ifndef INC_SIM_H_
#define INC_SIM_H_

void Sim_SendLocationDangerousStudent(float latitude, float longitude);
void Sim_SendLocationStudent(float latitude, float longitude);
void Sim_SendLocationDangerous(float latitude, float longitude);
void Sim_SendLocation(float latitude, float longitude);
void Sim_httpPost(float latitude, float longitude, uint8_t emergency);
#endif /* INC_SIM_H_ */
