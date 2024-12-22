#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    float tmp;
	float rain;
	float wpatt;
} weather;

typedef struct{
    char type[50];
    char stage[50];
    float yield;
    weather *fcst;
} crop;

typedef struct{
    char tool[50];
    int status;
    float fuel;
} equipment;

typedef struct{
    float soiln, ph, pest;
} sensor;

typedef struct{
    float lon, lat, soilh, moist;
    int ncrop, nequip, nsens;
    crop *c;
    equipment *e;
    sensor *s;
} field;

typedef struct{
    int nfields;
    field **f;
    float yield_pred;
} regionalhub;

weather* crfore(float tmp, float rain, float wpatt) {
    weather *fcst = (weather *)malloc(sizeof(weather));
    fcst->tmp = tmp;
    fcst->rain = rain;
    fcst->wpatt = wpatt;
    return fcst;
}

crop* crcrops(char *type, char *stage, float yield, weather *fcst) {
    crop *c = (crop *)malloc(sizeof(crop));
    strncpy(c->type, type, sizeof(c->type));
    strncpy(c->stage, stage, sizeof(c->stage));
    c->yield = yield;
    c->fcst = fcst;
    return c;
}

equipment* crequip(const char* tool, float fuel, int status) {
    equipment* eq = (equipment*)malloc(sizeof(equipment));
    strncpy(eq->tool, tool, sizeof(eq->tool));
    eq->fuel = fuel;
    eq->status = status;
    return eq;
}

sensor* crsensor(float soiln, float ph, float pest) {
    sensor *s = (sensor *)malloc(sizeof(sensor));
    s->soiln = soiln;
    s->ph = ph;
    s->pest = pest;
    return s;
}

field* create_field(float latitude, float longitude, float soilh, float moist, int ncrop, int nequip, int nsens) {
    field* fld = (field*)malloc(sizeof(field));
    fld->lat = latitude;
    fld->lon = longitude;
    fld->soilh = soilh;
    fld->moist = moist;
    fld->ncrop = ncrop;
    fld->nequip = nequip;
    fld->nsens = nsens;
    fld->c = (crop*)malloc(ncrop * sizeof(crop));
    fld->e = (equipment*)malloc(nequip * sizeof(equipment));
    fld->s = (sensor*)malloc(nsens * sizeof(sensor));
    return fld;
}

regionalhub* create_regional_hub(int nfields) {
    regionalhub* hub = (regionalhub*)malloc(sizeof(regionalhub));
    hub->nfields = nfields;
    hub->f = (field**)malloc(nfields * sizeof(field*));
    hub->yield_pred = 0.0;
    return hub;
}

int main() {
    weather* fcst1 = crfore(30.5, 100.0, 12.5);

    crop* crop1 = crcrops("Wheat", "Vegetative", 2.5, fcst1);
    crop* crop2 = crcrops("Corn", "Flowering", 3.0, fcst1);

    equipment* tractor = crequip("Tractor", 50.0, 1);
    equipment* drone = crequip("Drone", 10.0, 1);

    sensor* sensor1 = crsensor(6.0, 7.5, 2.0);
    sensor* sensor2 = crsensor(5.5, 7.0, 1.5);

    field* fld1 = create_field(12.34, 56.78, 85.0, 60.0, 2, 2, 2);
    fld1->c[0] = *crop1;  
    fld1->c[1] = *crop2;  
    fld1->e[0] = *tractor;  
    fld1->e[1] = *drone;    
    fld1->s[0] = *sensor1; 
    fld1->s[1] = *sensor2;  

    regionalhub* hub = create_regional_hub(1);
    hub->f[0] = fld1;

    printf("Regional Hub has %d fields\n", hub->nfields);
    printf("Field 1 GPS Location: %.2f, %.2f\n", fld1->lat, fld1->lon);
    printf("Field 1 Crop 1: %s, Growth Stage: %s, Expected Yield: %.2f tons\n", fld1->c[0].type, fld1->c[0].stage, fld1->c[0].yield);

    free(crop1);
    free(crop2);
    free(fcst1);
    free(tractor);
    free(drone);
    free(sensor1);
    free(sensor2);
    free(fld1->c);
    free(fld1->e);
    free(fld1->s);
    free(fld1);
    free(hub->f);
    free(hub);
}