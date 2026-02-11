#include <gtk/gtk.h>
#include <stdlib.h>
#include "PFL.h"
#include <string.h>

#define rv(y) strcmp((char *)&r,y)==0


void open_f (char *file_name){
    g_object_unref(G_OBJECT(pixb));
    pixb=gdk_pixbuf_new_from_file(file_name,NULL);
    g_object_unref(G_OBJECT(pixb_on_press));
    pixb_on_press=gdk_pixbuf_copy(pixb);
    g_object_set(main_im,"pixbuf",pixb,NULL);
    if (gdk_pixbuf_get_has_alpha(pixb))
        format = CAIRO_FORMAT_ARGB32;
    else
        format = CAIRO_FORMAT_RGB24;
    width = gdk_pixbuf_get_width (pixb);
    height = gdk_pixbuf_get_height (pixb);
    surface = cairo_image_surface_create (format, width, height);

}


void on_exit_programm_clicked(){
    gtk_main_quit();
}

void on_open_b_clicked(){
    gtk_widget_show(open_file);

}
void on_file_open_ok_clicked(){
    file_name=gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(f_open));
    open_f(file_name);

    gtk_widget_hide(open_file);
    on_overlay_clicked();
}
void on_f_open_file_activated(){
    on_file_open_ok_clicked();
}
void on_file_open_canel_clicked(){
    gtk_widget_hide(open_file);
    on_overlay_clicked();
}


void on_save_as_clicked(){
    gtk_widget_show(save_file);

}
void on_f_save_ok_clicked(){
    file_name=gtk_file_chooser_get_filename (GTK_FILE_CHOOSER(f_save));
    gchar *p = strrchr (file_name, (int)'.');
    p++;
    char r[6]={};
    strncat((char *)&r, p, 5);
    printf("%d\n",strcmp((char *)&r,"bmp")==0);
    if (rv("jpg")||rv("JPG")||rv("JPEG")||rv("jpeg")){
        gdk_pixbuf_save(pixb,file_name,"jpeg",NULL,"quality", "75",NULL);

    }
    else if (rv("png")||rv("PNG")){
        gdk_pixbuf_save(pixb,file_name,"png",NULL,NULL);
    }
    else if (rv("bmp")||rv("dib")||rv("rle")){
        gdk_pixbuf_save(pixb,file_name,"bmp",NULL,NULL);
    }
    else{
        gdk_pixbuf_save(pixb,file_name,"png",NULL,NULL);
    }
    open_f(file_name);
    gtk_widget_hide(save_file);
    on_overlay_clicked();
}
void on_f_save_canel_clicked(){
    gtk_widget_hide(save_file);
    on_overlay_clicked();
}

void on_save_clicked(){
    gchar *p = strrchr (file_name, (int)'.');
    p++;
    char r[6]={};
    strncat((char *)&r, p, 5);
    printf("%d\n",strcmp((char *)&r,"bmp")==0);
    if (rv("jpg")||rv("JPG")||rv("JPEG")||rv("jpeg")){
        gdk_pixbuf_save(pixb,file_name,"jpeg",NULL,"quality", "75",NULL);
        printf(")))\n");

    }
    else if (rv("png")||rv("PNG")){
        gdk_pixbuf_save(pixb,file_name,"png",NULL,NULL);
    }
    else if (rv("bmp")||rv("dib")||rv("rle")){
        gdk_pixbuf_save(pixb,file_name,"bmp",NULL,NULL);
    }
    else{
        gdk_pixbuf_save(pixb,file_name,"png",NULL,NULL);
    }

}
