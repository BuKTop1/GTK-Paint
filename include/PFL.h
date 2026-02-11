#pragma once

#include <gtk/gtk.h>

/* Глобальные переменные (определения находятся в main.c) */
extern GdkRGBA ucol[8], col1, col2;
extern GtkWidget *window;
extern GtkWidget *fixed;
extern GtkWidget *button_selection;
extern GtkWidget *image_selection;                            
extern GtkWidget *color_button1;
extern GtkWidget *draw_line1;
extern GtkWidget *color_button2;
extern GtkWidget *draw_line2;
extern GtkWidget *draw_figure;
extern GtkWidget *entry_line;
extern GtkWidget *label_width;
extern GtkWidget *menu_button;
extern GtkWidget *menu;
extern GtkWidget *file_name_bt;
extern GtkWidget *create;
extern GtkWidget *save;
extern GtkWidget *save_as;
extern GtkWidget *open_b;
extern GtkWidget *settings;
extern GtkWidget *draw_document;
extern GtkWidget *width_entry;
extern GtkWidget *height_entry;
extern GtkWidget *standart_size;
extern GtkWidget *exit_programm;
extern GtkWidget *color_dialog;
extern GtkWidget *color_chooser;
extern GtkWidget *menu_box;
extern GtkWidget *overlay;
extern GtkWidget *color1;
extern GtkWidget *color2;
extern GtkWidget *color3;
extern GtkWidget *color4;
extern GtkWidget *color5;
extern GtkWidget *color6;
extern GtkWidget *color7;
extern GtkWidget *color8;
extern GtkWidget *color9;
extern GtkWidget *color10;
extern GtkWidget *color11;
extern GtkWidget *color12;
extern GtkWidget *color13;
extern GtkWidget *color14;
extern GtkWidget *color15;
extern GtkWidget *color16;
extern GtkWidget *color17;
extern GtkWidget *color18;
extern GtkWidget *color19;
extern GtkWidget *color20;
extern GtkWidget *color21;
extern GtkWidget *color22;
extern GtkWidget *color23;
extern GtkWidget *black;
extern GtkWidget *color24;
extern GtkWidget *color25;
extern GtkWidget *color26;
extern GtkWidget *color27;
extern GtkWidget *color28;
extern GtkWidget *color29;
extern GtkWidget *color30;
extern GtkWidget *color31;
extern GtkWidget *main_im;
extern GtkWidget *main_bt;
extern GtkWidget *rectangle;
extern GtkWidget *elips;
extern GtkWidget *polygon;
extern GtkWidget *toggle_fill;
extern GtkWidget *toggle_line;
extern GtkWidget *rectangular_selection;
extern GtkWidget *direct_selection;
extern GtkWidget *custom_selection;
extern GtkWidget *color_choos;
extern GtkWidget *color_dialog_ok;
extern GtkWidget *color_dialog_canel;
extern GtkWidget *button_brush;
extern GtkWidget *button_straight;
extern GtkWidget *button_cruve;
extern GtkWidget *button_eraser;
extern GtkWidget *button_fill;
extern GtkWidget *button_magnifer;
extern GtkWidget *button_text;
extern GtkWidget *button_pipette;
extern GtkWidget *button_figure;
extern GtkWidget *open_file;
extern GtkWidget *save_file;
extern GtkWidget *f_open;
extern GtkWidget *f_save;

extern GtkBuilder *builder;

/* Другие глобальные переменные */
extern GdkPixbuf *pixb, *pixb_on_press;
extern GdkRGBA ucol[8], col1, col2;
extern gboolean press, fill, line, mouse;
extern gboolean thr;
extern gint line_w;
extern gint line_w1;
extern char line_s[4];
extern cairo_surface_t *surface;
extern cairo_t *cr;
extern gint width;
extern gint height;
extern gint format;
extern gchar *file_name;

/* Переменные для Drawing_events */
extern gint x, y;
extern gint rowstride, n_channels;
extern gchar *pixels;
extern gint cruve_flag;
extern gint cruve_xy[6];
extern GdkRGBA dr_col1, dr_col2;
extern gboolean button_on;

/* Типы перечислений */
typedef enum {
    rectangle_f,
    elips_f,
    polygon_f
} FigureType;

typedef enum {
    brush,
    straight,
    cruve,
    eraser,
    fill_in,
    magnifer,
    text,
    pipette,
    selection,
    figure_in
} InstrumentType;

/* Переменные перечислений */
extern FigureType figure;
extern InstrumentType instrument;

extern gulong h_ids[72];

/* Функции */
void set_ucol(GdkRGBA* col);
void on_menu_button_clicked(GtkButton *b);
void on_overlay_clicked();
void on_rectangle_activate();
void on_elips_activate();
void on_polygon_activate();
void on_toggle_fill_toggled(GtkToggleButton *b);
void on_toggle_line_toggled(GtkToggleButton *b);
void on_rectangular_selection_activate();
void on_direct_selection_activate();
void on_custom_selection_activate();
gboolean draw_line1_draw(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean draw_line2_draw(GtkWidget *widget, cairo_t *cr, gpointer data);
void on_color_choos_clicked(GtkWidget *b, GdkEvent *event);
void on_color_dialog_ok_clicked(GtkButton *b);
void on_color_dialog_canel_clicked(GtkButton *b);
void on_button_brush_toggled(GtkToggleButton *b);
void on_button_straight_toggled(GtkToggleButton *b);
void on_button_cruve_toggled(GtkToggleButton *b);
void on_button_eraser_toggled(GtkToggleButton *b);
void on_button_fill_toggled(GtkToggleButton *b);
void on_button_magnifer_toggled(GtkToggleButton *b);
void on_button_text_toggled(GtkToggleButton *b);
void on_button_pipette_toggled(GtkToggleButton *b);
void on_button_selection_toggled(GtkToggleButton *b);
void on_button_figure_toggled(GtkToggleButton *b);
void on_entry_line_activate(GtkEntry *b);
gboolean figure_draw(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean on_main_im_button_press_event(GtkWidget *widget, GdkEvent *event);

gboolean on_color24_draw(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean on_color25_draw(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean on_color26_draw(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean on_color27_draw(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean on_color28_draw(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean on_color29_draw(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean on_color30_draw(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean on_color31_draw(GtkWidget *widget, cairo_t *cr, gpointer data);
void on_color24_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color25_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color26_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color27_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color28_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color29_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color30_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color31_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color1_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color2_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color3_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color4_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color5_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color6_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color7_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color8_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color9_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color10_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color11_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color12_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color13_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color14_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color15_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color16_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color17_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color18_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color19_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color20_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color21_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color22_button_press_event(GtkWidget *b,GdkEvent *event);
void on_color23_button_press_event(GtkWidget *b,GdkEvent *event);
void on_black_button_press_event(GtkWidget *b,GdkEvent *event);

gboolean on_main_bt_button_press_event(GtkWidget *widget,GdkEvent *event);
gboolean on_main_bt_motion_notify_event(GtkWidget *widget, GdkEvent *event);
gboolean on_main_bt_button_release_event(GtkWidget *widget, GdkEvent *event);
void on_main_bt_leave();
