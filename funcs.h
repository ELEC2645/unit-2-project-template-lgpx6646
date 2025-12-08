#ifndef FUNCS_H
#define FUNCS_H

#define MAX_DATA 30

typedef enum{
    BUCK,
    BOOST
} converter_type;


converter_type converter_selector(void);
void inductor_selector_buck(void);
void inductor_selector_boost(void);
void capacitor_selector_buck(void);
void capacitor_selector_boost(void);
void boundary_current_buck(void);
void boundary_current_boost(void);
void menu_item_4(void);
int read_file(const char *filename);
int file_or_manual();
converter_type change_converter(void);

typedef struct {
    double Vin;
    double Vout;
    double L;
    double fs;
    double R;
    double deltav;
    double deltai;
} Converter;

#endif