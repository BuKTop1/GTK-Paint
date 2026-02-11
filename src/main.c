#include <gtk/gtk.h>
#include <stdlib.h>
#include <unistd.h> 
#include "PFL.h"

int main(int argc, char* argv[]){
    
    gtk_init(&argc,&argv);
    builder = gtk_builder_new_from_file("asserts/PFL.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
     //~ gtk_builder_connect_signals(builder,NULL);
    
    // getting widgets from PFL.glade
    fixed = GTK_WIDGET(gtk_builder_get_object(builder, "fixed"));
    draw_figure = GTK_WIDGET(gtk_builder_get_object(builder, "draw_figure"));
    button_selection = GTK_WIDGET(gtk_builder_get_object(builder, "button_selection"));
    image_selection = GTK_WIDGET(gtk_builder_get_object(builder, "image_selection"));
    color_button1 = GTK_WIDGET(gtk_builder_get_object(builder, "color_button1"));
    draw_line1 = GTK_WIDGET(gtk_builder_get_object(builder, "draw_line1"));
    color_button2 = GTK_WIDGET(gtk_builder_get_object(builder, "color_button2"));
    draw_line2 = GTK_WIDGET(gtk_builder_get_object(builder, "draw_line2"));
    entry_line = GTK_WIDGET(gtk_builder_get_object(builder, "entry_line"));
    label_width = GTK_WIDGET(gtk_builder_get_object(builder, "label_width"));
    menu_button = GTK_WIDGET(gtk_builder_get_object(builder, "menu_button"));
    menu = GTK_WIDGET(gtk_builder_get_object(builder, "menu"));
    file_name_bt = GTK_WIDGET(gtk_builder_get_object(builder, "file_name_bt"));
    create = GTK_WIDGET(gtk_builder_get_object(builder, "create"));
    save = GTK_WIDGET(gtk_builder_get_object(builder, "save"));
    save_as = GTK_WIDGET(gtk_builder_get_object(builder, "save_as"));
    open_b = GTK_WIDGET(gtk_builder_get_object(builder, "open_b"));
    settings = GTK_WIDGET(gtk_builder_get_object(builder, "settings"));
    draw_document = GTK_WIDGET(gtk_builder_get_object(builder, "draw_document"));
    width_entry = GTK_WIDGET(gtk_builder_get_object(builder, "width_entry"));
    height_entry = GTK_WIDGET(gtk_builder_get_object(builder, "height_entry"));
    standart_size = GTK_WIDGET(gtk_builder_get_object(builder, "standart_size"));
    exit_programm = GTK_WIDGET(gtk_builder_get_object(builder, "exit_programm"));
    color_dialog = GTK_WIDGET(gtk_builder_get_object(builder, "color_dialog"));
    color_chooser = GTK_WIDGET(gtk_builder_get_object(builder, "color_chooser"));
    menu_box = GTK_WIDGET(gtk_builder_get_object(builder, "menu_box"));
    overlay = GTK_WIDGET(gtk_builder_get_object(builder, "overlay"));
    color1 = GTK_WIDGET(gtk_builder_get_object(builder, "color1"));
    color2 = GTK_WIDGET(gtk_builder_get_object(builder, "color2"));
    color3 = GTK_WIDGET(gtk_builder_get_object(builder, "color3"));
    color4 = GTK_WIDGET(gtk_builder_get_object(builder, "color4"));
    color5 = GTK_WIDGET(gtk_builder_get_object(builder, "color5"));
    color6 = GTK_WIDGET(gtk_builder_get_object(builder, "color6"));
    color7 = GTK_WIDGET(gtk_builder_get_object(builder, "color7"));
    color8 = GTK_WIDGET(gtk_builder_get_object(builder, "color8"));
    color9 = GTK_WIDGET(gtk_builder_get_object(builder, "color9"));
    color10 = GTK_WIDGET(gtk_builder_get_object(builder, "color10"));
    color11 = GTK_WIDGET(gtk_builder_get_object(builder, "color11"));
    color12 = GTK_WIDGET(gtk_builder_get_object(builder, "color12"));
    color13 = GTK_WIDGET(gtk_builder_get_object(builder, "color13"));
    color14 = GTK_WIDGET(gtk_builder_get_object(builder, "color14"));
    color15 = GTK_WIDGET(gtk_builder_get_object(builder, "color15"));
    color16 = GTK_WIDGET(gtk_builder_get_object(builder, "color16"));
    color17 = GTK_WIDGET(gtk_builder_get_object(builder, "color17"));
    color18 = GTK_WIDGET(gtk_builder_get_object(builder, "color18"));
    color19 = GTK_WIDGET(gtk_builder_get_object(builder, "color19"));
    color20 = GTK_WIDGET(gtk_builder_get_object(builder, "color20"));
    color21 = GTK_WIDGET(gtk_builder_get_object(builder, "color21"));
    color22 = GTK_WIDGET(gtk_builder_get_object(builder, "color22"));
    color23 = GTK_WIDGET(gtk_builder_get_object(builder, "color23"));
    black = GTK_WIDGET(gtk_builder_get_object(builder, "black"));
    color24 = GTK_WIDGET(gtk_builder_get_object(builder, "color24"));
    color25 = GTK_WIDGET(gtk_builder_get_object(builder, "color25"));
    color26 = GTK_WIDGET(gtk_builder_get_object(builder, "color26"));
    color27 = GTK_WIDGET(gtk_builder_get_object(builder, "color27"));
    color28 = GTK_WIDGET(gtk_builder_get_object(builder, "color28"));
    color29 = GTK_WIDGET(gtk_builder_get_object(builder, "color29"));
    color30 = GTK_WIDGET(gtk_builder_get_object(builder, "color30"));
    color31 = GTK_WIDGET(gtk_builder_get_object(builder, "color31"));
    color31 = GTK_WIDGET(gtk_builder_get_object(builder, "color31"));
    main_im = GTK_WIDGET(gtk_builder_get_object(builder, "main_im"));
    main_bt = GTK_WIDGET(gtk_builder_get_object(builder, "main_bt"));
    color_dialog = GTK_WIDGET(gtk_builder_get_object(builder, "color_dialog"));
    rectangle = GTK_WIDGET(gtk_builder_get_object(builder, "rectangle"));
    elips = GTK_WIDGET(gtk_builder_get_object(builder, "elips"));
    polygon = GTK_WIDGET(gtk_builder_get_object(builder, "polygon"));
    toggle_fill = GTK_WIDGET(gtk_builder_get_object(builder, "toggle_fill"));
    toggle_line = GTK_WIDGET(gtk_builder_get_object(builder, "toggle_line"));
    rectangular_selection = GTK_WIDGET(gtk_builder_get_object(builder, "rectangular_selection"));
    direct_selection = GTK_WIDGET(gtk_builder_get_object(builder, "direct_selection"));
    custom_selection = GTK_WIDGET(gtk_builder_get_object(builder, "custom_selection"));
    draw_line1 = GTK_WIDGET(gtk_builder_get_object(builder, "draw_line1"));
    draw_line2 = GTK_WIDGET(gtk_builder_get_object(builder, "draw_line2"));
    color_choos = GTK_WIDGET(gtk_builder_get_object(builder, "color_choos"));
    color_dialog_ok = GTK_WIDGET(gtk_builder_get_object(builder, "color_dialog_ok"));
    color_dialog_canel = GTK_WIDGET(gtk_builder_get_object(builder, "color_dialog_canel"));
    button_brush = GTK_WIDGET(gtk_builder_get_object(builder, "button_brush"));
    button_straight = GTK_WIDGET(gtk_builder_get_object(builder, "button_straight"));
    button_cruve = GTK_WIDGET(gtk_builder_get_object(builder, "button_cruve"));
    button_eraser = GTK_WIDGET(gtk_builder_get_object(builder, "button_eraser"));
    button_fill = GTK_WIDGET(gtk_builder_get_object(builder, "button_fill"));
    button_magnifer = GTK_WIDGET(gtk_builder_get_object(builder, "button_magnifer"));
    button_text = GTK_WIDGET(gtk_builder_get_object(builder, "button_text"));
    button_pipette = GTK_WIDGET(gtk_builder_get_object(builder, "button_pipette"));
    button_figure = GTK_WIDGET(gtk_builder_get_object(builder, "button_figure"));
    main_bt = GTK_WIDGET(gtk_builder_get_object(builder, "main_bt"));
    open_file = GTK_WIDGET(gtk_builder_get_object(builder, "open_file"));
    f_open = GTK_WIDGET(gtk_builder_get_object(builder, "f_open"));
    save_file = GTK_WIDGET(gtk_builder_get_object(builder, "save_file"));
    f_save = GTK_WIDGET(gtk_builder_get_object(builder, "f_save"));

    
    // Linking signal handlers
    gtk_builder_connect_signals (builder, NULL);

	// Opening the initial file (temporarily)
    pixb=gdk_pixbuf_new_from_file("/home/buktop/Изображения/oboi.svg",NULL);
    g_object_set(main_im,"pixbuf",pixb,NULL);
    gtk_widget_add_events(main_bt, GDK_POINTER_MOTION_MASK);
    format = CAIRO_FORMAT_ARGB32;
    width = gdk_pixbuf_get_width (pixb);
    height = gdk_pixbuf_get_height (pixb);
    surface = cairo_image_surface_create (format, width, height);


    
    gtk_widget_hide_on_delete (color_dialog);
    
    // Linking to a css file
    GdkScreen *scr = gdk_screen_get_default();
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "PFL.css", NULL);
    gtk_style_context_add_provider_for_screen(scr,
                                      GTK_STYLE_PROVIDER(provider),
                                      GTK_STYLE_PROVIDER_PRIORITY_USER);
    gtk_style_context_reset_widgets(scr);

    // Initial values are set for variables
    gdk_rgba_parse(&col1,"#000");
    gdk_rgba_parse(&col2,"#fff");
    for(int i=0;i<8;i++){
        ucol[i].red=1;
        ucol[i].green=1;
        ucol[i].blue=1;
        ucol[i].alpha=1;
    }
    figure = rectangle_f;
    instrument = brush;
    pixb_on_press=gdk_pixbuf_copy(pixb);
 
    // program start
    gtk_widget_show(window);
    gtk_widget_hide(menu_box);
    gtk_main();
    gdk_pixbuf_save(pixb,"/home/buktop/Изображения/IM","png",NULL,"x-dpi","1","y-dpi","1",NULL);
        
    return 0;
}
void on_menu_button_clicked(GtkButton *b){

    if(!thr){
        thr=TRUE;
        gtk_widget_show(menu_box);
        for(int i=10;i<=290;i+=10){
            gtk_fixed_move(GTK_FIXED(fixed),menu,i-291,0);
            usleep(3000);
            while (gtk_events_pending()) gtk_main_iteration_do(FALSE);
        }
        gtk_fixed_move(GTK_FIXED(fixed),menu,0,0);
        thr=FALSE;
    }
}

void on_overlay_clicked(){
    if(!thr){
        thr=TRUE;
        for(int i=290;i>0;i-=10){
            
            gtk_fixed_move(GTK_FIXED(fixed),menu,i-291,0);
            usleep(3000);
            while (gtk_events_pending()) gtk_main_iteration_do(FALSE);
        }
        gtk_fixed_move(GTK_FIXED(fixed),menu,0,0);
        gtk_widget_hide(menu_box);
        thr=FALSE;

    }
}

gboolean figure_draw(GtkWidget *widget, cairo_t *cr, gpointer data){
    guint width, height;
    height = gtk_widget_get_allocated_height(widget);
    width = gtk_widget_get_allocated_width(widget);
    GtkStyleContext *context;
    context = gtk_widget_get_style_context (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    cairo_set_line_width(cr,2.0);
    if(line && !fill)
            cairo_set_line_width(cr,1.0);

    if(figure == rectangle_f)
        cairo_rectangle (cr, width/6+3,height/6+2,width/3*2-3,height/3*2-3);
    if (figure==elips_f)
        cairo_arc(cr,width/2,height/2,height/3,0,180);
        
    if(figure == polygon_f){
        cairo_move_to(cr, width/2+1,height/6);
        cairo_line_to(cr, width/6*5+3,height/6*5);
        cairo_line_to(cr, width/6+3,height/6*5);
        cairo_line_to(cr, width/2+1,height/6);
        cairo_set_line_join(cr, CAIRO_LINE_JOIN_ROUND); 

    }
    
    if(line)
    {
        gdk_cairo_set_source_rgba (cr, &col1);
        cairo_stroke_preserve(cr);
    }

    if(fill)
    {
        gdk_cairo_set_source_rgba (cr, &col2);
        cairo_fill(cr);
    }

    
    return FALSE;
}
void on_rectangle_activate(){
    figure = rectangle_f;
    gtk_widget_queue_draw(draw_figure);
}
void on_elips_activate(){
    figure = elips_f;
    gtk_widget_queue_draw(draw_figure);
}
void on_polygon_activate(){
    figure = polygon_f;
    gtk_widget_queue_draw(draw_figure);
}
void on_toggle_fill_toggled(GtkToggleButton *b){
    fill=gtk_toggle_button_get_active(b);
    gtk_widget_queue_draw(draw_figure);
}
void on_toggle_line_toggled(GtkToggleButton *b){
    line=gtk_toggle_button_get_active(b);
    gtk_widget_queue_draw(draw_figure);
}

void on_rectangular_selection_activate(){

    if (image_selection)
        gtk_container_remove(GTK_CONTAINER(button_selection),image_selection);
    image_selection = GTK_WIDGET(gtk_image_new_from_file(
                "/home/buktop/programm/image/rectangular_selection.svg"));
    gtk_container_add(GTK_CONTAINER(button_selection),image_selection);
    gtk_widget_show(image_selection);
}
void on_direct_selection_activate(){

    if (image_selection)
        gtk_container_remove(GTK_CONTAINER(button_selection),image_selection);
    image_selection = GTK_WIDGET(gtk_image_new_from_file(
                "/home/buktop/programm/image/direct_selection.svg"));
    gtk_container_add(GTK_CONTAINER(button_selection),image_selection);
    gtk_widget_show(image_selection);
}
void on_custom_selection_activate(){

    if (image_selection)
        gtk_container_remove(GTK_CONTAINER(button_selection),image_selection);
    image_selection = GTK_WIDGET(gtk_image_new_from_file(
                "/home/buktop/programm/image/custom_selection.svg"));
    gtk_container_add(GTK_CONTAINER(button_selection),image_selection);
    gtk_widget_show(image_selection);
}
gboolean draw_line1_draw(GtkWidget *widget, cairo_t *cr, gpointer data){
    guint width, height;
    height = gtk_widget_get_allocated_height(widget);
    width = gtk_widget_get_allocated_width(widget);
    GtkStyleContext *context;
    context = gtk_widget_get_style_context (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    cairo_set_line_width(cr,0.0);
    cairo_rectangle(cr,0,0,width,height);
    gdk_cairo_set_source_rgba (cr, &col2);
    cairo_fill(cr);
    cairo_set_line_width(cr,3.0);
    cairo_move_to(cr,0,height/2);
    cairo_line_to(cr,width,height/2);
    gdk_cairo_set_source_rgba (cr, &col1);
    cairo_stroke(cr);
    return FALSE;
}
gboolean draw_line2_draw(GtkWidget *widget, cairo_t *cr, gpointer data){
    guint width, height;
    height = gtk_widget_get_allocated_height(widget);
    width = gtk_widget_get_allocated_width(widget);
    GtkStyleContext *context;
    context = gtk_widget_get_style_context (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    cairo_set_line_width(cr,0.0);
    cairo_rectangle(cr,0,0,width,height);
    gdk_cairo_set_source_rgba (cr, &col1);
    cairo_fill(cr);
    cairo_set_line_width(cr,3.0);
    cairo_move_to(cr,0,height/2);
    cairo_line_to(cr,width,height/2);
    gdk_cairo_set_source_rgba (cr, &col2);
    cairo_stroke(cr);
    return FALSE;
}

void on_color_choos_clicked(GtkWidget *b,GdkEvent *event){
    mouse=(event->button.button == 1);
    gtk_widget_show(color_dialog);
}

void on_color_dialog_ok_clicked(GtkButton *b){
    GdkRGBA a;
    gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(color_chooser), &a);
    if(mouse) col1=a;
    else col2=a;
    set_ucol(&a);
    gtk_widget_hide(color_dialog);
}
void on_color_dialog_canel_clicked(GtkButton *b){
    gtk_widget_hide(color_dialog);
}



void on_button_brush_toggled(GtkToggleButton *b){
    if(gtk_toggle_button_get_active(b)){
        instrument = brush;
    }
}
void on_button_straight_toggled(GtkToggleButton *b){
    if(gtk_toggle_button_get_active(b)){
        instrument = straight;
    }
}
void on_button_cruve_toggled(GtkToggleButton *b){
    if(gtk_toggle_button_get_active(b)){
        instrument = cruve;
    }
}
void on_button_eraser_toggled(GtkToggleButton *b){
    if(gtk_toggle_button_get_active(b)){
        instrument = eraser;
    }
}
void on_button_fill_toggled(GtkToggleButton *b){
    if(gtk_toggle_button_get_active(b)){
        instrument = fill_in;
    }
}
void on_button_magnifer_toggled(GtkToggleButton *b){
    if(gtk_toggle_button_get_active(b)){
        instrument = magnifer;
    }
}
void on_button_text_toggled(GtkToggleButton *b){
    if(gtk_toggle_button_get_active(b)){
        instrument = text;
    }
}
void on_button_pipette_toggled(GtkToggleButton *b){
    if(gtk_toggle_button_get_active(b)){
        instrument = pipette;
    }
}
void on_button_selection_toggled(GtkToggleButton *b){
    if(gtk_toggle_button_get_active(b)){
        instrument = selection;
    }
}
void on_button_figure_toggled(GtkToggleButton *b){
    if(gtk_toggle_button_get_active(b)){
        instrument = figure_in;
    }
}

//~ void on_entry_line_focus(GtkEntry *b){
    //~ line_w1 = line_w;
//~ }

void on_entry_line_activate(GtkEntry *b){
    line_w=atoi(gtk_entry_get_text(b));
    if (line_w==0){
        line_w=line_w1;
        sprintf(line_s,"%d",line_w);
        gtk_entry_set_text(b,line_s);
    }
}
