#include <gtk/gtk.h>
#include "PFL.h"

void set_ucol(GdkRGBA* col){
    int i = 0;
    
    while(i<8&&!(ucol[i].red==1 &&
                ucol[i].green==1 &&
                ucol[i].blue==1 &&
                ucol[i].alpha==1)) i++;
    if (i<8){ 
        ucol[i]=*col;
        if(i==0)gtk_widget_queue_draw(color24);
        else if(i==1)gtk_widget_queue_draw(color25);
        else if(i==2)gtk_widget_queue_draw(color26);
        else if(i==3)gtk_widget_queue_draw(color27);
        else if(i==4)gtk_widget_queue_draw(color28);
        else if(i==5)gtk_widget_queue_draw(color29);
        else if(i==6)gtk_widget_queue_draw(color30);
        else if(i==7)gtk_widget_queue_draw(color31);
    }
    else{
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(color24))){
            ucol[0]=*col;
            gtk_widget_queue_draw(color24);
        }else
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(color25))){
            ucol[1]=*col;
            gtk_widget_queue_draw(color25);
        }else
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(color26))){
            ucol[2]=*col;
            gtk_widget_queue_draw(color26);
        }else
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(color27))){
            ucol[3]=*col;
            gtk_widget_queue_draw(color27);
        }else
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(color28))){
            ucol[4]=*col;
            gtk_widget_queue_draw(color28);
        }else
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(color29))){
            ucol[5]=*col;
            gtk_widget_queue_draw(color29);
        }else
        if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(color30))){
            ucol[6]=*col;
            gtk_widget_queue_draw(color30);
        }else
        {
            ucol[7]=*col;
            gtk_widget_queue_draw(color31);
        }
        
    }

}
gboolean on_color24_draw(GtkWidget *widget, cairo_t *cr, gpointer data){
    guint width, height;
    height = gtk_widget_get_allocated_height(widget);
    width = gtk_widget_get_allocated_width(widget);
    GtkStyleContext *context;
    context = gtk_widget_get_style_context (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    gdk_cairo_set_source_rgba (cr, &ucol[0]);
    cairo_rectangle (cr, 0,0,width,height);
    cairo_fill(cr);
    return FALSE;
}
gboolean on_color25_draw(GtkWidget *widget, cairo_t *cr, gpointer data){
    guint width, height;
    height = gtk_widget_get_allocated_height(widget);
    width = gtk_widget_get_allocated_width(widget);
    GtkStyleContext *context;
    context = gtk_widget_get_style_context (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    gdk_cairo_set_source_rgba (cr, &ucol[1]);
    cairo_rectangle (cr, 0,0,width,height);
    cairo_fill(cr);
    return FALSE;
}
gboolean on_color26_draw(GtkWidget *widget, cairo_t *cr, gpointer data){
    guint width, height;
    height = gtk_widget_get_allocated_height(widget);
    width = gtk_widget_get_allocated_width(widget);
    GtkStyleContext *context;
    context = gtk_widget_get_style_context (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    gdk_cairo_set_source_rgba (cr, &ucol[2]);
    cairo_rectangle (cr, 0,0,width,height);
    cairo_fill(cr);
    return FALSE;
}
gboolean on_color27_draw(GtkWidget *widget, cairo_t *cr, gpointer data){
    guint width, height;
    height = gtk_widget_get_allocated_height(widget);
    width = gtk_widget_get_allocated_width(widget);
    GtkStyleContext *context;
    context = gtk_widget_get_style_context (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    gdk_cairo_set_source_rgba (cr, &ucol[3]);
    cairo_rectangle (cr, 0,0,width,height);
    cairo_fill(cr);
    return FALSE;
}
gboolean on_color28_draw(GtkWidget *widget, cairo_t *cr, gpointer data){
    guint width, height;
    height = gtk_widget_get_allocated_height(widget);
    width = gtk_widget_get_allocated_width(widget);
    GtkStyleContext *context;
    context = gtk_widget_get_style_context (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    gdk_cairo_set_source_rgba (cr, &ucol[4]);
    cairo_rectangle (cr, 0,0,width,height);
    cairo_fill(cr);
    return FALSE;
}
gboolean on_color29_draw(GtkWidget *widget, cairo_t *cr, gpointer data){
    guint width, height;
    height = gtk_widget_get_allocated_height(widget);
    width = gtk_widget_get_allocated_width(widget);
    GtkStyleContext *context;
    context = gtk_widget_get_style_context (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    gdk_cairo_set_source_rgba (cr, &ucol[5]);
    cairo_rectangle (cr, 0,0,width,height);
    cairo_fill(cr);
    return FALSE;
}
gboolean on_color30_draw(GtkWidget *widget, cairo_t *cr, gpointer data){
    guint width, height;
    height = gtk_widget_get_allocated_height(widget);
    width = gtk_widget_get_allocated_width(widget);
    GtkStyleContext *context;
    context = gtk_widget_get_style_context (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    gdk_cairo_set_source_rgba (cr, &ucol[6]);
    cairo_rectangle (cr, 0,0,width,height);
    cairo_fill(cr);
    return FALSE;
}
gboolean on_color31_draw(GtkWidget *widget, cairo_t *cr, gpointer data){
    guint width, height;
    height = gtk_widget_get_allocated_height(widget);
    width = gtk_widget_get_allocated_width(widget);
    GtkStyleContext *context;
    context = gtk_widget_get_style_context (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    gdk_cairo_set_source_rgba (cr, &ucol[7]);
    cairo_rectangle (cr, 0,0,width,height);
    cairo_fill(cr);
    return FALSE;
}
void on_color24_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        col2=ucol[0];
    else
        col1=ucol[0];
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color25_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        col2=ucol[1];
    else
        col1=ucol[1];
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color26_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        col2=ucol[2];
    else
        col1=ucol[2];
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color27_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        col2=ucol[3];
    else
        col1=ucol[3];
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color28_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        col2=ucol[4];
    else
        col1=ucol[4];
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color29_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        col2=ucol[5];
    else
        col1=ucol[5];
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color30_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        col2=ucol[6];
    else
        col1=ucol[6];
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color31_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        col2=ucol[7];
    else
        col1=ucol[7];
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}

void on_color1_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#808080");
    else
        gdk_rgba_parse(&col1,"#808080");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color2_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#f00");
    else
        gdk_rgba_parse(&col1,"#f00");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color3_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#FF8000");
    else
        gdk_rgba_parse(&col1,"#FF8000");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color4_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#ff0");
    else
        gdk_rgba_parse(&col1,"#ff0");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color5_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#0f0");
    else
        gdk_rgba_parse(&col1,"#0f0");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color6_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#0ff");
    else
        gdk_rgba_parse(&col1,"#0ff");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color7_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#0080FF");
    else
        gdk_rgba_parse(&col1,"#0080FF");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color8_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#00f");
    else
        gdk_rgba_parse(&col1,"#00f");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color9_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#8000ff");
    else
        gdk_rgba_parse(&col1,"#8000ff");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color10_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#f0f");
    else
        gdk_rgba_parse(&col1,"#f0f");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color11_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#ff0080");
    else
        gdk_rgba_parse(&col1,"#ff0080");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color12_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#fff");
    else
        gdk_rgba_parse(&col1,"#fff");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color13_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#800000");
    else
        gdk_rgba_parse(&col1,"#800000");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color14_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#804000");
    else
        gdk_rgba_parse(&col1,"#804000");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color15_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#808000");
    else
        gdk_rgba_parse(&col1,"#808000");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color16_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#008000");
    else
        gdk_rgba_parse(&col1,"#008000");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color17_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#008080");
    else
        gdk_rgba_parse(&col1,"#008080");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color18_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#004080");
    else
        gdk_rgba_parse(&col1,"#004080");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color19_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#000080");
    else
        gdk_rgba_parse(&col1,"#000080");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color20_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#400080");
    else
        gdk_rgba_parse(&col1,"#400080");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color21_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#800080");
    else
        gdk_rgba_parse(&col1,"#800080");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color22_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#800040");
    else
        gdk_rgba_parse(&col1,"#800040");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_color23_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#404040");
    else
        gdk_rgba_parse(&col1,"#404040");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}
void on_black_button_press_event(GtkWidget *b,GdkEvent *event){
    if(event->button.button == 3) 
        gdk_rgba_parse(&col2,"#000");
    else
        gdk_rgba_parse(&col1,"#000");
    gtk_widget_queue_draw(draw_figure);
    gtk_widget_queue_draw(draw_line1);
    gtk_widget_queue_draw(draw_line2);
}

