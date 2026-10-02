//
// Created by arekstasko on 8/24/26.
//

#ifndef PLANT_SERVICE_H
#define PLANT_SERVICE_H

int perform_water_supply(int plantId);
void process_executed_water_supply(int status_id, int status_code);
bool verify_awaiting_water_supply(int status_id);

#endif //PLANT_SERVICE_H
