/* globals.c - определения глобальных переменных */

#include <gtk/gtk.h>

/* Все глобальные переменные объявлены здесь  */

/* GTK виджеты */
GtkWidget *window;
GtkWidget *fixed;
GtkWidget *button_selection;
GtkWidget *image_selection;
GtkWidget *color_button1;
GtkWidget *draw_line1;
GtkWidget *color_button2;
GtkWidget *draw_line2;
GtkWidget *draw_figure;
GtkWidget *entry_line;
GtkWidget *label_width;
GtkWidget *menu_button;
GtkWidget *menu;
GtkWidget *file_name_bt;
GtkWidget *create;
GtkWidget *save;
GtkWidget *save_as;
GtkWidget *open_b;
GtkWidget *settings;
GtkWidget *draw_document;
GtkWidget *width_entry;
GtkWidget *height_entry;
GtkWidget *standart_size;
GtkWidget *exit_programm;
GtkWidget *color_dialog;
GtkWidget *color_chooser;
GtkWidget *menu_box;
GtkWidget *overlay;
GtkWidget *color1;
GtkWidget *color2;
GtkWidget *color3;
GtkWidget *color4;
GtkWidget *color5;
GtkWidget *color6;
GtkWidget *color7;
GtkWidget *color8;
GtkWidget *color9;
GtkWidget *color10;
GtkWidget *color11;
GtkWidget *color12;
GtkWidget *color13;
GtkWidget *color14;
GtkWidget *color15;
GtkWidget *color16;
GtkWidget *color17;
GtkWidget *color18;
GtkWidget *color19;
GtkWidget *color20;
GtkWidget *color21;
GtkWidget *color22;
GtkWidget *color23;
GtkWidget *black;
GtkWidget *color24;
GtkWidget *color25;
GtkWidget *color26;
GtkWidget *color27;
GtkWidget *color28;
GtkWidget *color29;
GtkWidget *color30;
GtkWidget *color31;
GtkWidget *main_im;
GtkWidget *main_bt;
GtkWidget *rectangle;
GtkWidget *elips;
GtkWidget *polygon;
GtkWidget *toggle_fill;
GtkWidget *toggle_line;
GtkWidget *rectangular_selection;
GtkWidget *direct_selection;
GtkWidget *custom_selection;
GtkWidget *color_choos;
GtkWidget *color_dialog_ok;
GtkWidget *color_dialog_canel;
GtkWidget *button_brush;
GtkWidget *button_straight;
GtkWidget *button_cruve;
GtkWidget *button_eraser;
GtkWidget *button_fill;
GtkWidget *button_magnifer;
GtkWidget *button_text;
GtkWidget *button_pipette;
GtkWidget *button_figure;
GtkWidget *open_file;
GtkWidget *save_file;
GtkWidget *f_open;
GtkWidget *f_save;

GtkBuilder *builder;

/* Цветовые переменные */
GdkRGBA ucol[8] = {{0}};
GdkRGBA col1 = {0};
GdkRGBA col2 = {0};
GdkPixbuf *pixb = NULL;
GdkPixbuf *pixb_on_press = NULL;

/* Флаги и параметры */
gboolean press = FALSE;
gboolean fill = TRUE;
gboolean line = TRUE;
gboolean mouse = FALSE;
gboolean thr = FALSE;
gboolean button_on = FALSE;

/* Размеры и форматы */
gint width = 0;
gint height = 0;
gint format = 0;
gint line_w = 1;
gint line_w1 = 1;
gchar *file_name = NULL;
char line_s[4] = {0};

/* Значения для рисования */
cairo_surface_t *surface = NULL;
cairo_t *cr = NULL;

/* Координаты и параметры Drawing */
gint x = 0;
gint y = 0;
gint rowstride = 0;
gint n_channels = 0;
gchar *pixels = NULL;
gint cruve_flag = 0;
gint cruve_xy[6] = {0};
GdkRGBA dr_col1 = {0};
GdkRGBA dr_col2 = {0};

/* Перечисления */
enum {rectangle_f, elips_f, polygon_f} figure = 0;
enum {
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
} instrument = 0;

/* Обработчики сигналов */
gulong h_ids[72] = {0};
