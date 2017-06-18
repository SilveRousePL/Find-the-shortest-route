#pragma once

/* OBSLUGA
 * Klawisz V - Dodawanie wierzcho�k�w
 * Klawisz C - Dodawanie po�acze� (mo�liwe r�wnie� wprowadzanie kosztu klawiszami numerycznymi) BackSpace r�wnie� dzia�a
 * Klawisz D - Usuwanie
 * Klawisz F - Wyszukiwanie najkr�tszej �cie�ki
 * Klawisz N - Nowy graf
 * Klawisz O - Wczytaj graf
 * Klawisz S - Zapisz graf
 * Klawisz ESC - Wyj�cie z ka�dego trybu pracy lub wyj�cie z programu
 */

//Tryby pracy
enum Mode
{
	NONE, //�aden, mo�na manipulowa� wierzcho�kami przeswaj�c je, wczyta� plik lub zapisa�
	ADD_VERTEX, //Dodawanie wierzcho�k�w, po klikni�ciu w okre�lony punkt pojawia si� tam nowy wierzcho�ek
	ADD_CONNECT, //Dodawanie po��cze� 
	//Mo�liwe ��czenie wierzcho�k�w poprzez klikni�cie kolejno na pocz�tkowy, a potem na ko�cowy.
	//Mo�na ustawia� koszt po��czenia, w tym celu nale�y w tym trybie przed po��czeniem wierzcho�k�w
	//wpisa� liczb� za pomoc� klawiatury. Obecny koszt jest wy�wietlany w komunikacie na spodzie okna.
	REMOVE, //Usuwanie po��cze�
	FIND, //Znajdowanie najkr�tszej �cie�ki
	//Nale�y kolejno klikn�� w wierzcho�ek pocz�tkowy naszej trasy, a potem w ko�cowy, aby sprawdzi�,
	//czy istnieje pomi�dzy nimi po�aczenie i je�li tak, dana trasa ��cz�ca dane wierzcho�ki zostanie
	//pod�wietlona na zielono, a koszt ca�kowity trasy i tekstowa reprezentacja trasy zostanie wy�wietlona
	//w komunikacie na spodzie okna.
};