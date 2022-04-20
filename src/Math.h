/* inclusion unique du fichier dans la compilation du projet */
#pragma once

#include <iostream>

/* création d'une structure vecteur pour les positions et déplacements des différentes entités */
struct Vector2f
{
    //initialisation basique sans arguments
	Vector2f()
	:x(0.0f), y(0.0f)
	{}

    //initialisation avec spécifications des coordonnées
	Vector2f(float p_x, float p_y)
	:x(p_x), y(p_y)
	{}

    //affichage des coordonnées actuelles du vecteur
	void print()
	{
		std::cout << x << ", " << y << std::endl;
	}

	float x, y;
};