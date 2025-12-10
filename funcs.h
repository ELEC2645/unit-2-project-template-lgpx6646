#ifndef FUNCS_H
#define FUNCS_H

#define MAX_DATA 30

typedef enum{
    BUCK,
    BOOST
} converter_type;

typedef struct {
    double Vin;
    double Vout;
    double L;
    double fs;
    double R;
    double deltav;
    double deltai;
} Converter;


converter_type converter_selector(void);
void inductor_selector_buck(void);
void inductor_selector_boost(void);
void capacitor_selector_buck(void);
void capacitor_selector_boost(void);
int boundary_current_buck(void);
int boundary_current_boost(void);
Converter* read_file(const char *filename, int *count);
Converter* file_or_manual(int *count);
converter_type change_converter(void);

#endif