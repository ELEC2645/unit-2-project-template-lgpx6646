#ifndef FUNCS_H
#define FUNCS_H

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
void read_file(const char *filename);
converter_type change_converter(void);

#endif