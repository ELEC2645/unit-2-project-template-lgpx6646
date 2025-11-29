#ifndef FUNCS_H
#define FUNCS_H

typedef enum{
    BUCK,
    BOOST
} converter_type;


converter_type converter_selector(void);
void inductor_selector_buck(void);
void inductor_selector_boost(void);
void menu_item_2(void);
void menu_item_3(void);
void menu_item_4(void);
void change_converter(void);

#endif