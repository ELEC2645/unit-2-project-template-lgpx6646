#ifndef FUNCS_H
#define FUNCS_H

typedef enum{
    buck_converter,
    boost_converter
} converter_type;


converter_type converter_selector(void);
void menu_item_1(void);
void menu_item_2(void);
void menu_item_3(void);
void menu_item_4(void);
void menu_item_5(void);

#endif