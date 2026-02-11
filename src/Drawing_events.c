#include <gtk/gtk.h>
#include <stdlib.h>
#include <malloc.h>	
#include "PFL.h"

void drawing_brush (GtkWidget *widget, GdkEvent *event);
void drawing_straight (GtkWidget *widget, GdkEvent *event);
void draw_straight(GtkWidget *widget, GdkEvent *event);
void drawing_cruve (GtkWidget *widget, GdkEvent *event);
void drawing_eraser (GtkWidget *widget, GdkEvent *event);
void drawing_fill (int x,int y);
void drawing_magnifer (GtkWidget *widget, GdkEvent *event);
void drawing_text (GtkWidget *widget, GdkEvent *event);
void drawing_pipette (int x,int y);
void drawing_selection (GtkWidget *widget, GdkEvent *event);
void drawing_figure_in (GtkWidget *widget, GdkEvent *event);
void fill_func(int x1, int y1, char color[4]);
void lining(int x1, int y1, int x2, int y2,  char color[4]);
gboolean sp(char *p1,char *p2);
char* gp(int x, int y);

gboolean on_main_bt_button_press_event(GtkWidget *widget,GdkEvent *event){

    press = TRUE;    
    if(instrument!=cruve||cruve_flag==0){
        g_object_unref(G_OBJECT(pixb_on_press));
        pixb_on_press=gdk_pixbuf_copy(pixb);
        if(event->button.button!=3){
            mouse=TRUE;
            dr_col1=col1;
            dr_col2=col2;
        }else{
            mouse=FALSE;
            dr_col1=col2;
            dr_col2=col1;
        }
    }
    
    x=event->button.x;
    y=event->button.y;
    
    if (instrument==brush||instrument==eraser){
        free(cr);
        cr = cairo_create (surface);
        gdk_cairo_set_source_pixbuf (cr, pixb, 0, 0);
        cairo_paint (cr);
        if (instrument==brush)
            gdk_cairo_set_source_rgba(cr,&dr_col1);
        else
            gdk_cairo_set_source_rgba(cr,&dr_col2);
        cairo_set_line_cap(cr,CAIRO_LINE_CAP_ROUND);
        cairo_set_line_width(cr,line_w);
    }
    else if(instrument==pipette||instrument==fill_in){
        rowstride = gdk_pixbuf_get_rowstride (pixb);
        n_channels = gdk_pixbuf_get_n_channels (pixb);
        pixels = gdk_pixbuf_get_pixels (pixb);
        if(instrument==pipette)
            drawing_pipette(x,y);
        else if(instrument==fill_in)
            drawing_fill(x,y);
    }
        
    return FALSE;
}
gboolean on_main_bt_motion_notify_event(GtkWidget *widget, GdkEvent *event){
    if(press){
        switch (instrument){
            case brush:
                drawing_brush(widget,event);
                break;
            case straight:
                draw_straight(widget,event);
                break;
            case cruve:
                drawing_cruve(widget,event);
                break;
            case eraser:
                drawing_eraser(widget,event);
                break;
            case fill_in:
                drawing_fill(event->button.x,event->button.y);
                break;
            case magnifer:
                drawing_magnifer(widget,event);
                break;
            case text:
                drawing_text(widget,event);
                break;
            case pipette:
                drawing_pipette(event->button.x,event->button.y);
                break;
            case selection:
                drawing_selection(widget,event);
                break;
            case figure_in:
                drawing_figure_in(widget,event);
                break;
        }
    }
}
gboolean on_main_bt_button_release_event(GtkWidget *widget, GdkEvent *event){
    if(instrument==cruve){
        if(cruve_flag==0){
            cruve_xy[0]=x;
            cruve_xy[1]=y;
            cruve_xy[2]=event->button.x;
            cruve_xy[3]=event->button.y;
            cruve_flag=1;
        }
        else if(cruve_flag==1){
            cruve_xy[4]=x;
            cruve_xy[5]=y;
            cruve_flag=2;
        }
        else if(cruve_flag==2)
            cruve_flag=0;
    }else if(cruve_flag!=0) cruve_flag=0;
    press=FALSE;
    return FALSE;
}
void drawing_brush (GtkWidget *widget, GdkEvent *event){
    cairo_move_to(cr,x,y);
    cairo_line_to(cr,event->button.x,event->button.y);
    
    cairo_stroke(cr);

    g_object_unref(G_OBJECT(pixb));
    pixb=gdk_pixbuf_get_from_surface(surface,0,0,width,height);
    gtk_image_set_from_pixbuf(GTK_IMAGE(main_im),pixb);    
    x = event->button.x;
    y = event->button.y;
}
void drawing_straight (GtkWidget *widget, GdkEvent *event){
    cr = cairo_create (surface);
    gdk_cairo_set_source_pixbuf (cr, pixb_on_press, 0, 0);
    cairo_paint (cr);
    gdk_cairo_set_source_rgba(cr,&dr_col1);
    cairo_move_to(cr,x,y);
    cairo_line_to(cr,event->button.x,event->button.y);
    
    cairo_set_line_width(cr,line_w);
    cairo_stroke_preserve(cr);
    g_object_unref(G_OBJECT(pixb));
    pixb=gdk_pixbuf_get_from_surface(surface,0,0,width,height);
    gtk_image_set_from_pixbuf(GTK_IMAGE(main_im),pixb);    
}
void draw_straight(GtkWidget *widget, GdkEvent *event){
	char color[4];
    if (!mouse){
        color[0]=(unsigned char)(col2.red*255);
        color[1]=(unsigned char)(col2.green*255);
        color[2]=(unsigned char)(col2.blue*255);
        color[3]=(unsigned char)(col2.alpha*255);
    }
    else{
        color[0]=(unsigned char)(col1.red*255);
        color[1]=(unsigned char)(col1.green*255);
        color[2]=(unsigned char)(col1.blue*255);
        color[3]=(unsigned char)(col1.alpha*255);
    }
    g_object_unref(G_OBJECT(pixb));
    pixb = gdk_pixbuf_copy(pixb_on_press);
    printf("1\n");
    pixels = gdk_pixbuf_get_pixels (pixb);

    lining(x,y,event->button.x,event->button.y,color);
    gtk_image_set_from_pixbuf(GTK_IMAGE(main_im),pixb);
    


}
void drawing_cruve (GtkWidget *widget, GdkEvent *event){
    if(cruve_flag==0){
        cr = cairo_create (surface);
        gdk_cairo_set_source_pixbuf (cr, pixb_on_press, 0, 0);
        cairo_paint (cr);
        gdk_cairo_set_source_rgba(cr,&dr_col1);
        cairo_move_to(cr,x,y);
        cairo_line_to(cr,event->button.x,event->button.y);
    }
    else if(cruve_flag==1){
        x=event->button.x;
        y=event->button.y;
        cr = cairo_create (surface);
        gdk_cairo_set_source_pixbuf (cr, pixb_on_press, 0, 0);
        cairo_paint (cr);
        gdk_cairo_set_source_rgba(cr,&dr_col1)  ;
        cairo_move_to(cr,cruve_xy[0],cruve_xy[1]);
        cairo_curve_to(cr,x,y,x,y,
                        cruve_xy[2],cruve_xy[3]);
        cairo_set_line_width(cr,line_w);
    }
    else if(cruve_flag==2){
        x=event->button.x;
        y=event->button.y;
        cr = cairo_create (surface);
        gdk_cairo_set_source_pixbuf (cr, pixb_on_press, 0, 0);
        cairo_paint (cr);
        gdk_cairo_set_source_rgba(cr,&dr_col1);
        cairo_move_to(cr,cruve_xy[0],cruve_xy[1]);
        cairo_curve_to(cr,cruve_xy[4],cruve_xy[5],x,y,
                        cruve_xy[2],cruve_xy[3]);
        cairo_set_line_width(cr,line_w);
    }
    
    cairo_set_line_width(cr,line_w);
    cairo_stroke_preserve(cr);
    g_object_unref(G_OBJECT(pixb));
    pixb=gdk_pixbuf_get_from_surface(surface,0,0,width,height);
    gtk_image_set_from_pixbuf(GTK_IMAGE(main_im),pixb);    
}
void drawing_eraser (GtkWidget *widget, GdkEvent *event){
    cairo_move_to(cr,x,y);
    cairo_line_to(cr,event->button.x,event->button.y);
    
    cairo_stroke(cr);

    g_object_unref(G_OBJECT(pixb));
    pixb=gdk_pixbuf_get_from_surface(surface,0,0,width,height);
    gtk_image_set_from_pixbuf(GTK_IMAGE(main_im),pixb);    
    x = event->button.x;
    y = event->button.y;
}
void drawing_fill (int x, int y){
    if(width>x && x>0 && height>y && y>0){
        char color[4];
        if (!mouse){
            color[0]=(unsigned char)(col2.red*255);
            color[1]=(unsigned char)(col2.green*255);
            color[2]=(unsigned char)(col2.blue*255);
            color[3]=(unsigned char)(col2.alpha*255);
            fill_func(x,y,color);
        }
        else{
            color[0]=(unsigned char)(col1.red*255);
            color[1]=(unsigned char)(col1.green*255);
            color[2]=(unsigned char)(col1.blue*255);
            color[3]=(unsigned char)(col1.alpha*255);
            fill_func(x,y,color);
        }
        gtk_image_set_from_pixbuf(GTK_IMAGE(main_im),pixb);    
    }
}
void drawing_text (GtkWidget *widget, GdkEvent *event){

}
void drawing_selection (GtkWidget *widget, GdkEvent *event){
    
}
void drawing_figure_in (GtkWidget *widget, GdkEvent *event){
    
    gdouble f_width, f_height;
    f_width = event->button.x-x;
    f_height = event->button.y-y;
    cr = cairo_create (surface);
    gdk_cairo_set_source_pixbuf (cr, pixb_on_press, 0, 0);
    cairo_paint(cr);
    
    if(figure==rectangle_f){
        if(fill && line){
            if(abs(f_width)<=line_w*2 || abs(f_height)<=line_w*2){
                cairo_rectangle (cr, x, y,f_width, f_height);
                gdk_cairo_set_source_rgba(cr,&dr_col1);
                cairo_fill(cr);
            }else{
                gint loc_x,loc_y,loc_width,loc_height;
                if (f_width<0){
                    loc_x=x-line_w;
                    loc_width = f_width+line_w*2;
                } else{
                    loc_x=x+line_w;
                    loc_width = f_width-line_w*2;
                }
                if (f_height<0){
                    loc_y=y-line_w;
                    loc_height = f_height+line_w*2;
                } else{
                    loc_y=y+line_w;
                    loc_height = f_height-line_w*2;
                }
                
                cairo_rectangle (cr, loc_x, loc_y,loc_width, loc_height);
                gdk_cairo_set_source_rgba(cr,&dr_col2);
                cairo_fill(cr);
                
                g_object_unref(G_OBJECT(pixb));
                pixb=gdk_pixbuf_get_from_surface(surface,0,0,width,height);
                cr = cairo_create (surface);
                gdk_cairo_set_source_pixbuf (cr, pixb, 0, 0);
                
                if (f_width<0){
                    loc_x=x-line_w/2;
                    loc_width = f_width+line_w;
                } else{
                    loc_x=x+line_w/2;
                    loc_width = f_width-line_w;
                }
                if (f_height<0){
                    loc_y=y-line_w/2;
                    loc_height = f_height+line_w;
                } else{
                    loc_y=y+line_w/2;
                    loc_height = f_height-line_w;
                }
                cairo_rectangle (cr, loc_x, loc_y, loc_width, loc_height);
                gdk_cairo_set_source_rgba(cr,&dr_col1);
                cairo_set_line_width(cr,line_w);
                cairo_stroke_preserve(cr);
            }
        }
        else if(fill){
            cairo_rectangle (cr, x, y,f_width, f_height);
            gdk_cairo_set_source_rgba(cr,&dr_col2);
            cairo_fill(cr);
        }
        

        else if(line){
            if(abs(f_width)<=line_w*2 || abs(f_height)<=line_w*2){
                cairo_rectangle (cr, x, y,f_width, f_height);
                gdk_cairo_set_source_rgba(cr,&dr_col1);
                cairo_fill(cr);
            }else{
                if(fill){
                    cr = cairo_create (surface);
                    gdk_cairo_set_source_pixbuf (cr, pixb, 0, 0);
                }
                gint loc_x,loc_y,loc_width,loc_height;
                if (f_width<0){
                    loc_x=x-line_w/2;
                    loc_width = f_width+line_w;
                } else{
                    loc_x=x+line_w/2;
                    loc_width = f_width-line_w;
                }
                if (f_height<0){
                    loc_y=y-line_w/2;
                    loc_height = f_height+line_w;
                } else{
                    loc_y=y+line_w/2;
                    loc_height = f_height-line_w;
                }
                cairo_rectangle (cr, loc_x, loc_y, loc_width, loc_height);
                gdk_cairo_set_source_rgba(cr,&dr_col1);
                cairo_set_line_width(cr,line_w);
                cairo_stroke_preserve(cr);
            }
        }
    }
    
    else if(figure==elips_f){
        gdouble cof = f_width/f_height;
        cr = cairo_create (surface);
        gdk_cairo_set_source_pixbuf (cr, pixb_on_press, 0, 0);
        cairo_paint (cr);
        
        cairo_matrix_t save_matrix;
        cairo_get_matrix(cr, &save_matrix);
        cairo_scale(cr, cof, 1);
        cairo_new_path(cr);
        
        cairo_arc (cr, 
                     (f_width / 2 + x)/cof,
                     (f_height/2 + y),
                     abs(f_height/2),
                     0,180);
        cairo_set_matrix(cr, &save_matrix);
        if (line){
            gdk_cairo_set_source_rgba(cr,&dr_col1);
            cairo_set_line_width(cr,line_w);
            cairo_stroke_preserve(cr);
        }
        if(fill){
            gdk_cairo_set_source_rgba(cr,&dr_col2);
            cairo_fill(cr);
        }
    }

    g_object_unref(G_OBJECT(pixb));
    pixb=gdk_pixbuf_get_from_surface(surface,0,0,width,height);
    gtk_image_set_from_pixbuf(GTK_IMAGE(main_im),pixb);        
}
void drawing_magnifer (GtkWidget *widget, GdkEvent *event){
  
}
void drawing_pipette (int x, int y){
    if(width>x && x>0 && height>y && y>0){
        gchar *p = pixels + y * rowstride + x * n_channels;
        if (!mouse){
            col2.red=(unsigned char)p[0]/255.0;
            col2.green=(unsigned char)p[1]/255.0;
            col2.blue=(unsigned char)p[2]/255.0;
            if (n_channels==4){
                col2.alpha=(unsigned char)p[3]/255.0;
            }else
                col2.alpha=1;
        }
        else{
            col1.red=(unsigned char)p[0]/255.0;
            col1.green=(unsigned char)p[1]/255.0;
            col1.blue=(unsigned char)p[2]/255.0;
            if (n_channels==4)
                col1.alpha=(unsigned char)p[3]/255.0;
            else
                col1.alpha=1;
        }
        gtk_widget_queue_draw(draw_figure);
        gtk_widget_queue_draw(draw_line1);
        gtk_widget_queue_draw(draw_line2);
    }
}

void fill_func(int x1, int y1, char color[4]){
    int a,n=5;
    int **cor = (int **) malloc(5*sizeof(int *));
    for (int i=0; i<5; i++)
		cor[i] = (int *) malloc(2*sizeof(int *));
	for (int i=0;i<5;i++)
		for (int h=0;h<2;h++)
			cor [i][h]=0;
    for(int i = 0;cor[0][0]!=-1; i++){
		a=0;
        if(i==0){
            if(y1<height-1 &&
               sp(gp(x1,y1+1),gp(x1,y1))&&
               !sp(gp(x1,y1+1),color)){
                cor[a][0]=x1;
                cor[a][1]=y1+1;
                a++;
            }
            if(y1>0 &&
               sp(gp(x1,y1-1),gp(x1,y1))&&
               !sp(gp(x1,y1-1),color)){
                cor[a][0]=x1;
                cor[a][1]=y1-1;
                a++;
            }
            if(x1<width-1 &&
               sp(gp(x1+1,y1),gp(x1,y1))&&
               !sp(gp(x1+1,y1),color)){
                cor[a][0]=x1+1;
                cor[a][1]=y1;
                a++;
            }
            if(x1>0 &&
               sp(gp(x1-1,y1),gp(x1,y1))&&
               !sp(gp(x1-1,y1),color)){
                cor[a][0]=x1-1;
                cor[a][1]=y1;
                a++;
            }
            gp(x1,y1)[0]=color[0];
            gp(x1,y1)[1]=color[1];
            gp(x1,y1)[2]=color[2];
       } else{
		n=(i-1)*4*4+1;
       	int **cor1 = (int **) malloc((i*4*4+1)*sizeof(int *));
        for (int h=0; h<i*4*4+1; h++)
			cor1[h] = (int *) malloc(2*sizeof(int *));	
		for (int h=0;h<i*4*4+1;h++)
			for (int j=0;j<2;j++)
				cor1 [h][j]=0;

       	for (int h=0;cor[h][0]!=-1;h++){
			if(cor[h][1]<(height-1)&&
			   sp(gp(cor[h][0],cor[h][1]+1),gp(cor[h][0],cor[h][1]))&&
			   !sp(gp(cor[h][0],cor[h][1]+1),color)){
				cor1[a][0]=cor[h][0];
				cor1[a][1]=cor[h][1]+1;
				a++;
			}

			if(cor[h][1]>0&&
			   sp(gp(cor[h][0],cor[h][1]-1),gp(cor[h][0],cor[h][1]))&&
			   !sp(gp(cor[h][0],cor[h][1]-1),color)){
				cor1[a][0]=cor[h][0];
				cor1[a][1]=cor[h][1]-1;
				a++;
			}
		   if(cor[h][0]<(width-1)&&
			   sp(gp(cor[h][0]+1,cor[h][1]),gp(cor[h][0],cor[h][1]))&&
			   !sp(gp(cor[h][0]+1,cor[h][1]),color)){
				cor1[a][0]=(cor[h][0])+1;
				cor1[a][1]=(cor[h][1]);
				a++;
			}

			if(cor[h][0]>0&&
			   sp(gp(cor[h][0]-1,cor[h][1]),gp(cor[h][0],cor[h][1]))&&
			   !sp(gp(cor[h][0]-1,cor[h][1]),color)){
				cor1[a][0]=cor[h][0]-1;
				cor1[a][1]=cor[h][1];
				a++;
			}

			gp(cor[h][0],cor[h][1])[0]=color[0];
			gp(cor[h][0],cor[h][1])[1]=color[1];
			gp(cor[h][0],cor[h][1])[2]=color[2];
	   

		}
		for (int h=0; h<n; h++)
			free (cor[h]); 
		free (cor);
		cor=cor1;
		
       }
       cor[a][0]=-1;
    }
	for (int h=0; h<n; h++)
		free(cor[h]); 
	free (cor);

}
void lining(int x1, int y1, int x2, int y2,  char color[4]){
    int dx = x1-x2,
        dy = y1-y2;
    float tg,x3,y3;
    printf("%d %d %d %d \n",x1,x2,y,y2);
    gboolean bl=abs(dx)>abs(dy);
    tg = bl? dy/dx:dx/dy;
    if (bl){
        if (x1<x2){
            x3=x1;
            y3=y1;
        }else{
            x3=x2;
            y3=y2;
        }
        for (;x3 != MAX(x1,x2);){
            gp((int)x3,(int)y3)[0]=color[0];
            gp((int)x3,(int)y3)[0]=color[1];
            gp((int)x3,(int)y3)[0]=color[2];
            x3++;
            y3+=tg;
        }
    }else{
        if (y1<y2){
            y3=y1;
            x3=x1;
        }else{
            x3=x2;
            y3=y2;
        }
        for (;y3 != MAX(y1,y2);){
            gp((int)x3,(int)y3)[0]=color[0];
            gp((int)x3,(int)y3)[0]=color[1];
            gp((int)x3,(int)y3)[0]=color[2];
            y3++;
            x3+=tg;
        }
    }
}

gboolean sp(char *p1,char *p2){
    gboolean b = ( abs((unsigned char)(p1[0]) - (unsigned char)(p2[0]) )<2&&
                   abs((unsigned char)(p1[1]) - (unsigned char)(p2[1]) )<2&&
                   abs((unsigned char)(p1[2]) - (unsigned char)(p2[2]) )<2);
    if (n_channels==4)
        b = b && abs( (unsigned char)(p1[3]) - (unsigned char)(p2[3]) )<5;
    return b;
}
char* gp(int x, int y){
      return pixels + y*rowstride + x* n_channels;
}
