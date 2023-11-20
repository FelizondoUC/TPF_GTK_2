/*
 ============================================================================
 Name        : TPF_GTK.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in GTK+
 ============================================================================
 */

#include <gtk/gtk.h>
#include "variables.h"
#include "TPF_4.0.h"

GtkWidget *Ventana_Principal;
GtkWidget *ventanaReglas1;
GtkWidget *Ventana_Reglas2;
GtkWidget *Ventana_Creditos;
GtkWidget *Ventana_Jugar;
GtkWidget *Ventana_Jugar2;
GtkWidget *Ventana_Empezar_Partida;
GtkWidget *Ventana_Rendirse;

GObject *Boton_Reglas_Menu;
GObject *Volver_A_Menu_Reglas1;
GObject *Boton_Siguiente_Reglas;
GObject *Boton_PaganteReglas1_Reglas2;
GObject *Volver_A_Menu_Reglas2;
GObject *Boton_Creditos;
GObject *Volver_A_Menu_Creditos;
GObject *Boton_Jugar;
GObject *Volver_al_Menu_Jugar;
GtkToggleButton *Humano_VS_PC;
GtkToggleButton *PC_vs_Humano;
GtkToggleButton *Al_Azar;
GtkToggleButton *PC_vs_PC;
GtkToggleButton *Seleccionar_Red;
GtkToggleButton *Seleccionar_Green;
GObject *Siguiente_Jugar;
GObject *Volver_al_Menu_Jugar2;
GtkToggleButton *IA_Aleatoria;
GtkToggleButton *IA_Inteligente;
GtkBuilder *builder;
GtkEntry *Nombre_Jugador1;
GtkEntry *Nombre_Jugador2;
GObject *Siguiente_Jugar2;
GObject *Boton_Ayuda_Juego;
GObject *Boton_Acerca_de_Juego;
GObject *Boton_Rendirse_Juego;
GObject *Boton_continuar_ventRendirse;
GObject *Rendirse_Ventana_Rendirse;
GObject *boton1;
GObject *boton2;
GObject *boton3;
GObject *boton4;
GObject *boton5;
GObject *boton6;
GObject *boton7;
GObject *boton8;
GObject *boton9;
GObject *boton10;
GObject *boton11;
GObject *boton12;
GObject *boton13;
GObject *boton14;
GObject *boton15;
GObject *boton16;
GObject *boton17;
GObject *boton18;
GObject *boton19;
GObject *boton20;
GObject *boton21;
GObject *boton22;
GObject *boton23;
GObject *boton24;
GObject *boton25;
GObject *Dado_Boton1;
GObject *Dado_Boton2;
GObject *Dado_Boton3;
GObject *Dado_Boton4;
GObject *Dado_Boton5;
GObject *Dado_Boton6;
GObject *Dado_Boton7;
GObject *Dado_Boton8;
GObject *Dado_Boton9;
GObject *Dado_Boton10;
GObject *Dado_Boton11;
GObject *Dado_Boton12;
GObject *Dado_Boton13;
GObject *Dado_Boton14;
GObject *Dado_Boton15;
GObject *Dado_Boton16;
GObject *Dado_Boton17;
GObject *Dado_Boton18;
GObject *Dado_Boton19;
GObject *Dado_Boton20;
GObject *Dado_Boton21;
GObject *Dado_Boton22;
GObject *Dado_Boton23;
GObject *Dado_Boton24;
GObject *Dado_Boton25;

int opcion;
int color;
int IA;
int board_gtk[TAM_MAX][TAM_MAX];

void funcOcultar(GObject *widet, gpointer data)
{
	gtk_widget_hide(data);
}

void funcLlamar(GObject *cosito, gpointer data)
{
	gtk_widget_show_all (data);
}

void funcMostrarOcultar1 (GObject *boton, gpointer data)
{
	gtk_widget_hide(ventanaReglas1);
	gtk_widget_show_all (Ventana_Reglas2);
}

void funcMostrarOcultar2 (GObject *boton, gpointer data)
{
	gtk_widget_hide(Ventana_Reglas2);
	gtk_widget_show_all (ventanaReglas1);
}

void funcMostrarOcultar3 (GObject *boton, gpointer data)
{
	gtk_widget_hide(Ventana_Principal);
	gtk_widget_show_all (Ventana_Jugar);
}

void funcMostrarOcultar4 (GObject *boton, gpointer data)
{
	gtk_widget_hide(Ventana_Jugar);
	gtk_widget_show_all (Ventana_Principal);
}

void funcMostrarOcultar5 (GObject *boton, gpointer data)
{
	gtk_widget_hide(Ventana_Jugar);
	gtk_widget_show_all (Ventana_Jugar2);
}

void funcMostrarOcultar6 (GObject *boton, gpointer data)
{
	gtk_widget_hide(Ventana_Jugar2);
	gtk_widget_show_all (Ventana_Jugar);
}

void funcMostrarOcultar7 (GObject *boton, gpointer data)
{
	gtk_widget_hide(Ventana_Empezar_Partida);
	gtk_widget_hide(Ventana_Rendirse);
	gtk_widget_show_all (Ventana_Principal);
}

void funcBotonesModoJuego1(GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PC_vs_Humano), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Al_Azar), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PC_vs_PC), FALSE);
		opcion = 1;
	}
}

void funcBotonesModoJuego2(GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Humano_VS_PC), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Al_Azar), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PC_vs_PC), FALSE);
		opcion = 2;
	}
}

void funcBotonesModoJuego3(GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PC_vs_Humano), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Humano_VS_PC), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PC_vs_PC), FALSE);
		opcion = 4;
	}
}

void funcBotonesModoJuego4(GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(PC_vs_Humano), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Al_Azar), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Humano_VS_PC), FALSE);
		opcion = 3;
	}
}

void funcColorRed(GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Seleccionar_Green), FALSE);
		color = 1;
	}
}

void funcColorGreen(GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(Seleccionar_Red), FALSE);
		color = 2;
	}
}

void funcBotonesIA1 (GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
		{
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(IA_Inteligente), FALSE);
			IA = 1;
		}
}

void funcBotonesIA2 (GtkToggleButton *boton, gpointer data)
{
	if (gtk_toggle_button_get_active(boton))
		{
			gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(IA_Aleatoria), FALSE);
			IA = 3;
		}
}


void comenzar_juego (GObject *boton, gpointer data)
{
	gtk_widget_hide(Ventana_Jugar2);
	gtk_widget_show_all (Ventana_Empezar_Partida);
	main_C (opcion, color, IA);

}

void colocar_imagen1()
{
	if(color == 1)
	{
		Dado_Boton1 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton1),Dado_Boton1);
	}else if (color == 2)
	{
		Dado_Boton1 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton1),Dado_Boton1);
	}
}

void colocar_imagen2()
{
	if(color == 1)
	{
		Dado_Boton2 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton2),Dado_Boton2);
	}else if (color == 2)
	{
		Dado_Boton2 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton2),Dado_Boton2);
	}
}

void colocar_imagen3()
{
	if(color == 1)
	{
		Dado_Boton3 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton3),Dado_Boton3);
	}else if (color == 2)
	{
		Dado_Boton3 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton3),Dado_Boton3);
	}
}

void colocar_imagen4()
{
	if(color == 1)
	{
		Dado_Boton4 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton4),Dado_Boton4);
	}else if (color == 2)
	{
		Dado_Boton4 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton4),Dado_Boton4);
	}
}

void colocar_imagen5()
{
	if(color == 1)
	{
		Dado_Boton5 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton5),Dado_Boton5);
	}else if (color == 2)
	{
		Dado_Boton5 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton5),Dado_Boton5);
	}
}

void colocar_imagen6()
{
	if(color == 1)
	{
		Dado_Boton6 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton6),Dado_Boton6);
	}else if (color == 2)
	{
		Dado_Boton6 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton6),Dado_Boton6);
	}
}

void colocar_imagen7()
{
	if(color == 1)
	{
		Dado_Boton7 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton7),Dado_Boton7);
	}else if (color == 2)
	{
		Dado_Boton7 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton7),Dado_Boton7);
	}
}

void colocar_imagen8()
{
	if(color == 1)
	{
		Dado_Boton8 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton8),Dado_Boton8);
	}else if (color == 2)
	{
		Dado_Boton8 = gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton8),Dado_Boton8);
	}
}

void colocar_imagen9()
{
	if(color == 1)
	{
		Dado_Boton9 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton9),Dado_Boton9);
	}else if (color == 2)
	{
		Dado_Boton9 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton9),Dado_Boton9);
	}
}

void colocar_imagen10()
{
	if(color == 1)
	{
		Dado_Boton10 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton10),Dado_Boton10);
	}else if (color == 2)
	{
		Dado_Boton10 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton10),Dado_Boton10);
	}
}

void colocar_imagen11()
{
	if(color == 1)
	{
		Dado_Boton11 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton11),Dado_Boton11);
	}else if (color == 2)
	{
		Dado_Boton11 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton11),Dado_Boton11);
	}
}

void colocar_imagen12()
{
	if(color == 1)
	{
		Dado_Boton12 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton12),Dado_Boton12);
	}else if (color == 2)
	{
		Dado_Boton12 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton12),Dado_Boton12);
	}
}

void colocar_imagen13()
{
	if(color == 1)
	{
		Dado_Boton13 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton13),Dado_Boton13);
	}else if (color == 2)
	{
		Dado_Boton13 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton13),Dado_Boton13);
	}
}

void colocar_imagen14()
{
	if(color == 1)
	{
		Dado_Boton14 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton14),Dado_Boton14);
	}else if (color == 2)
	{
		Dado_Boton14 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton14),Dado_Boton14);
	}
}

void colocar_imagen15()
{
	if(color == 1)
	{
		Dado_Boton15 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton15),Dado_Boton15);
	}else if (color == 2)
	{
		Dado_Boton15 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton15),Dado_Boton15);
	}
}

void colocar_imagen16()
{
	if(color == 1)
	{
		Dado_Boton16 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton16),Dado_Boton16);
	}else if (color == 2)
	{
		Dado_Boton16 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton16),Dado_Boton16);
	}
}

void colocar_imagen17()
{
	if(color == 1)
	{
		Dado_Boton17 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton17),Dado_Boton17);
	}else if (color == 2)
	{
		Dado_Boton17 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton17),Dado_Boton17);
	}
}

void colocar_imagen18()
{
	if(color == 1)
	{
		Dado_Boton18 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton18),Dado_Boton18);
	}else if (color == 2)
	{
		Dado_Boton18 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton18),Dado_Boton18);
	}
}

void colocar_imagen19()
{
	if(color == 1)
	{
		Dado_Boton19 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton19),Dado_Boton19);
	}else if (color == 2)
	{
		Dado_Boton19 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton19),Dado_Boton19);
	}
}

void colocar_imagen20()
{
	if(color == 1)
	{
		Dado_Boton20 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton20),Dado_Boton20);
	}else if (color == 2)
	{
		Dado_Boton20 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton20),Dado_Boton20);
	}
}

void colocar_imagen21()
{
	if(color == 1)
	{
		Dado_Boton21 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton21),Dado_Boton21);
	}else if (color == 2)
	{
		Dado_Boton21 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton21),Dado_Boton21);
	}
}

void colocar_imagen22()
{
	if(color == 1)
	{
		Dado_Boton22 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton22),Dado_Boton22);
	}else if (color == 2)
	{
		Dado_Boton22 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton22),Dado_Boton22);
	}
}

void colocar_imagen23()
{
	if(color == 1)
	{
		Dado_Boton23 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton23),Dado_Boton23);
	}else if (color == 2)
	{
		Dado_Boton23 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton23),Dado_Boton23);
	}
}

void colocar_imagen24()
{
	if(color == 1)
	{
		Dado_Boton24 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton24),Dado_Boton24);
	}else if (color == 2)
	{
		Dado_Boton24 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton24),Dado_Boton24);
	}
}

void colocar_imagen25()
{
	if(color == 1)
	{
		Dado_Boton25 =  gtk_image_new_from_file("Dado_Rojo1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton25),Dado_Boton25);
	}else if (color == 2)
	{
		Dado_Boton25 =  gtk_image_new_from_file("Dado_Verde1.jpeg");
		gtk_button_set_image(GTK_BUTTON(boton25),Dado_Boton25);
	}
}

 int main (int argc, char *argv[])
 {
	 //Punteros a elementos del Glade
    gtk_init (&argc, &argv);

    builder = gtk_builder_new_from_file("TPFgtk.V1");
    Ventana_Principal = GTK_WIDGET(gtk_builder_get_object(builder,"Ventana_Principal"));
    Ventana_Creditos = GTK_WIDGET(gtk_builder_get_object(builder,"Ventana_Creditos"));
    ventanaReglas1 = GTK_WIDGET(gtk_builder_get_object(builder,"Ventana_Reglas1"));
    Ventana_Reglas2 = GTK_WIDGET(gtk_builder_get_object(builder,"Ventana_Reglas2"));
    Ventana_Jugar = GTK_WIDGET(gtk_builder_get_object(builder, "Ventana_Jugar"));
    Ventana_Jugar2 = GTK_WIDGET(gtk_builder_get_object(builder, "Ventana_Jugar2"));
    Ventana_Empezar_Partida = GTK_WIDGET(gtk_builder_get_object(builder,"Ventana_Empezar_Partida"));
    Ventana_Rendirse = GTK_WIDGET(gtk_builder_get_object(builder,"Ventana_Rendirse"));

    //Asiganción de los botones de las distintas ventanas
    Boton_Reglas_Menu = gtk_builder_get_object(builder,"Boton_Reglas_Menu");
    Volver_A_Menu_Reglas1 = gtk_builder_get_object(builder, "Volver_A_Menu_Reglas1");
    Boton_Siguiente_Reglas = gtk_builder_get_object(builder,"Boton_Siguiente_Reglas");
    Boton_PaganteReglas1_Reglas2 = gtk_builder_get_object(builder, "Boton_PaganteReglas1_Reglas2");
    Volver_A_Menu_Reglas2 = gtk_builder_get_object(builder, "Volver_A_Menu_Reglas2");
    Boton_Creditos = gtk_builder_get_object(builder, "Boton_Creditos");
    Volver_A_Menu_Creditos = gtk_builder_get_object(builder, "Volver_A_Menu_Creditos");
    Boton_Jugar = gtk_builder_get_object(builder,"Boton_Jugar");
    Volver_al_Menu_Jugar = gtk_builder_get_object(builder,"Volver_al_Menu_Jugar");
    Humano_VS_PC = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"Humano_VS_PC"));
    PC_vs_Humano = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"PC_vs_Humano"));
    Al_Azar = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"Al_Azar"));
    PC_vs_PC = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"PC_vs_PC"));
    Seleccionar_Red = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"Seleccionar_Red"));
    Seleccionar_Green = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"Seleccionar_Green"));
    Siguiente_Jugar = gtk_builder_get_object(builder,"Siguiente_Jugar");
    Volver_al_Menu_Jugar2 = gtk_builder_get_object(builder, "Volver_al_Menu_Jugar2");
    IA_Aleatoria = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"IA_Aleatoria"));
    IA_Inteligente = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder,"IA_Inteligente"));
    Nombre_Jugador1 = GTK_ENTRY(gtk_builder_get_object(builder,"Nombre_Jugador1"));
    Nombre_Jugador2 = GTK_ENTRY(gtk_builder_get_object(builder,"Nombre_Jugador2"));
    Siguiente_Jugar2 = gtk_builder_get_object(builder,"Siguiente_Jugar2");
    Boton_Ayuda_Juego = gtk_builder_get_object (builder,"Boton_Ayuda_Juego");
    Boton_Acerca_de_Juego = gtk_builder_get_object (builder,"Boton_Acerca_de_Juego");
    Boton_Rendirse_Juego = gtk_builder_get_object (builder,"Boton_Rendirse_Juego");
    Boton_continuar_ventRendirse = gtk_builder_get_object (builder,"Boton_continuar_ventRendirse");
    Rendirse_Ventana_Rendirse = gtk_builder_get_object (builder,"Rendirse_Ventana_Rendirse");
    //Asignacion de los punteros de los botones del tablero
    boton1 = gtk_builder_get_object (builder, "boton1");
    boton2 = gtk_builder_get_object (builder, "boton2");
    boton3 = gtk_builder_get_object (builder, "boton3");
    boton4 = gtk_builder_get_object (builder, "boton4");
    boton5 = gtk_builder_get_object (builder, "boton5");
    boton6 = gtk_builder_get_object (builder, "boton6");
    boton7 = gtk_builder_get_object (builder, "boton7");
    boton8 = gtk_builder_get_object (builder, "boton8");
    boton9 = gtk_builder_get_object (builder, "boton9");
    boton10 = gtk_builder_get_object (builder, "boton10");
    boton11 = gtk_builder_get_object (builder, "boton11");
    boton12 = gtk_builder_get_object (builder, "boton12");
    boton13 = gtk_builder_get_object (builder, "boton13");
    boton14 = gtk_builder_get_object (builder, "boton14");
    boton15 = gtk_builder_get_object (builder, "boton15");
    boton16 = gtk_builder_get_object (builder, "boton16");
    boton17 = gtk_builder_get_object (builder, "boton17");
    boton18 = gtk_builder_get_object (builder, "boton18");
    boton19 = gtk_builder_get_object (builder, "boton19");
    boton20 = gtk_builder_get_object (builder, "boton20");
    boton21 = gtk_builder_get_object (builder, "boton21");
    boton22 = gtk_builder_get_object (builder, "boton22");
    boton23 = gtk_builder_get_object (builder, "boton23");
    boton24 = gtk_builder_get_object (builder, "boton24");
    boton25 = gtk_builder_get_object (builder, "boton25");

    //Asignación de las imágenes de los botones del tablero

    Dado_Boton1 = gtk_builder_get_object (builder,"Dado_Boton1");
    Dado_Boton2 = gtk_builder_get_object (builder,"Dado_Boton2");
    Dado_Boton3 = gtk_builder_get_object (builder,"Dado_Boton3");
    Dado_Boton4 = gtk_builder_get_object (builder,"Dado_Boton4");
    Dado_Boton5 = gtk_builder_get_object (builder,"Dado_Boton5");
    Dado_Boton6 = gtk_builder_get_object (builder,"Dado_Boton6");
    Dado_Boton7 = gtk_builder_get_object (builder,"Dado_Boton7");
    Dado_Boton8 = gtk_builder_get_object (builder,"Dado_Boton8");
    Dado_Boton9 = gtk_builder_get_object (builder,"Dado_Boton9");
    Dado_Boton10 = gtk_builder_get_object (builder,"Dado_Boton10");
    Dado_Boton11 = gtk_builder_get_object (builder,"Dado_Boton11");
    Dado_Boton12 = gtk_builder_get_object (builder,"Dado_Boton12");
    Dado_Boton13 = gtk_builder_get_object (builder,"Dado_Boton13");
    Dado_Boton14 = gtk_builder_get_object (builder,"Dado_Boton14");
    Dado_Boton15 = gtk_builder_get_object (builder,"Dado_Boton15");
    Dado_Boton16 = gtk_builder_get_object (builder,"Dado_Boton16");
    Dado_Boton17 = gtk_builder_get_object (builder,"Dado_Boton17");
    Dado_Boton18 = gtk_builder_get_object (builder,"Dado_Boton18");
    Dado_Boton19 = gtk_builder_get_object (builder,"Dado_Boton19");
    Dado_Boton20 = gtk_builder_get_object (builder,"Dado_Boton20");
    Dado_Boton21 = gtk_builder_get_object (builder,"Dado_Boton21");
    Dado_Boton22 = gtk_builder_get_object (builder,"Dado_Boton22");
    Dado_Boton23 = gtk_builder_get_object (builder,"Dado_Boton23");
    Dado_Boton24 = gtk_builder_get_object (builder,"Dado_Boton24");
    Dado_Boton25 = gtk_builder_get_object (builder,"Dado_Boton25");

    //Callbacks que terminan el codigo
    g_signal_connect (Ventana_Principal, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect (Ventana_Jugar, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect (Ventana_Jugar2, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    g_signal_connect (Ventana_Empezar_Partida, "destroy", G_CALLBACK (gtk_main_quit), NULL);


    g_signal_connect (Boton_Reglas_Menu, "clicked", G_CALLBACK (funcLlamar), ventanaReglas1);
    g_signal_connect (Volver_A_Menu_Reglas1, "clicked", G_CALLBACK (funcOcultar), ventanaReglas1);
    g_signal_connect (Boton_Siguiente_Reglas, "clicked", G_CALLBACK(funcMostrarOcultar1), NULL);
    g_signal_connect (Boton_PaganteReglas1_Reglas2, "clicked", G_CALLBACK(funcMostrarOcultar2), NULL);
    g_signal_connect (Volver_A_Menu_Reglas2, "clicked", G_CALLBACK (funcOcultar), Ventana_Reglas2);
    g_signal_connect (Boton_Creditos, "clicked", G_CALLBACK (funcLlamar), Ventana_Creditos);
    g_signal_connect (Volver_A_Menu_Creditos, "clicked", G_CALLBACK (funcOcultar), Ventana_Creditos);
    g_signal_connect (Boton_Jugar, "clicked", G_CALLBACK (funcMostrarOcultar3), Ventana_Jugar);
    g_signal_connect (Volver_al_Menu_Jugar, "clicked", G_CALLBACK (funcMostrarOcultar4),NULL);
    g_signal_connect (Siguiente_Jugar, "clicked", G_CALLBACK (funcMostrarOcultar5), NULL);
    g_signal_connect (Volver_al_Menu_Jugar2, "clicked", G_CALLBACK (funcMostrarOcultar6), NULL);
    g_signal_connect (Humano_VS_PC, "toggled", G_CALLBACK (funcBotonesModoJuego1), Ventana_Jugar);
    g_signal_connect (PC_vs_Humano, "toggled", G_CALLBACK (funcBotonesModoJuego2), Ventana_Jugar);
    g_signal_connect (Al_Azar, "toggled", G_CALLBACK (funcBotonesModoJuego3), Ventana_Jugar);
    g_signal_connect (PC_vs_PC, "toggled", G_CALLBACK (funcBotonesModoJuego4), Ventana_Jugar);
    g_signal_connect (Seleccionar_Red, "toggled", G_CALLBACK (funcColorRed), Ventana_Jugar);
    g_signal_connect (Seleccionar_Green, "toggled", G_CALLBACK (funcColorGreen), Ventana_Jugar);
    g_signal_connect (IA_Aleatoria, "toggled", G_CALLBACK (funcBotonesIA1), NULL);
    g_signal_connect (IA_Inteligente, "toggled", G_CALLBACK (funcBotonesIA2), NULL);
    g_signal_connect (Siguiente_Jugar2, "clicked", G_CALLBACK(comenzar_juego), NULL);
    g_signal_connect (Boton_Ayuda_Juego, "clicked", G_CALLBACK(funcLlamar), ventanaReglas1);
    g_signal_connect (Boton_Acerca_de_Juego, "clicked", G_CALLBACK(funcLlamar),Ventana_Creditos);
    g_signal_connect (Boton_Rendirse_Juego, "clicked",G_CALLBACK(funcLlamar), Ventana_Rendirse);
    g_signal_connect (Boton_continuar_ventRendirse, "clicked", G_CALLBACK(funcOcultar), Ventana_Rendirse);
    g_signal_connect (Rendirse_Ventana_Rendirse, "clicked", G_CALLBACK(gtk_main_quit),NULL);
    g_signal_connect (boton1, "clicked", G_CALLBACK(colocar_imagen1),NULL);
    g_signal_connect (boton2, "clicked", G_CALLBACK(colocar_imagen2),NULL);
    g_signal_connect (boton3, "clicked", G_CALLBACK(colocar_imagen3),NULL);
    g_signal_connect (boton4, "clicked", G_CALLBACK(colocar_imagen4),NULL);
    g_signal_connect (boton5, "clicked", G_CALLBACK(colocar_imagen5),NULL);
    g_signal_connect (boton6, "clicked", G_CALLBACK(colocar_imagen6),NULL);
    g_signal_connect (boton7, "clicked", G_CALLBACK(colocar_imagen7),NULL);
    g_signal_connect (boton8, "clicked", G_CALLBACK(colocar_imagen8),NULL);
    g_signal_connect (boton9, "clicked", G_CALLBACK(colocar_imagen9),NULL);
    g_signal_connect (boton10, "clicked", G_CALLBACK(colocar_imagen10),NULL);
    g_signal_connect (boton11, "clicked", G_CALLBACK(colocar_imagen11),NULL);
    g_signal_connect (boton12, "clicked", G_CALLBACK(colocar_imagen12),NULL);
    g_signal_connect (boton13, "clicked", G_CALLBACK(colocar_imagen13),NULL);
    g_signal_connect (boton14, "clicked", G_CALLBACK(colocar_imagen14),NULL);
    g_signal_connect (boton15, "clicked", G_CALLBACK(colocar_imagen15),NULL);
    g_signal_connect (boton16, "clicked", G_CALLBACK(colocar_imagen16),NULL);
    g_signal_connect (boton17, "clicked", G_CALLBACK(colocar_imagen17),NULL);
    g_signal_connect (boton18, "clicked", G_CALLBACK(colocar_imagen18),NULL);
    g_signal_connect (boton19, "clicked", G_CALLBACK(colocar_imagen19),NULL);
    g_signal_connect (boton20, "clicked", G_CALLBACK(colocar_imagen20),NULL);
    g_signal_connect (boton21, "clicked", G_CALLBACK(colocar_imagen21),NULL);
    g_signal_connect (boton22, "clicked", G_CALLBACK(colocar_imagen22),NULL);
    g_signal_connect (boton23, "clicked", G_CALLBACK(colocar_imagen23),NULL);
    g_signal_connect (boton24, "clicked", G_CALLBACK(colocar_imagen24),NULL);
    g_signal_connect (boton25, "clicked", G_CALLBACK(colocar_imagen25),NULL);


    gtk_widget_show_all (Ventana_Principal);

    gtk_main ();

    return 0;
 }
