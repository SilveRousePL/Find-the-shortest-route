#pragma once

/* OBSLUGA
 * Klawisz V - Dodawanie wierzcho³ków
 * Klawisz C - Dodawanie po³aczeñ (mo¿liwe równie¿ wprowadzanie kosztu klawiszami numerycznymi) BackSpace równie¿ dzia³a
 * Klawisz D - Usuwanie
 * Klawisz F - Wyszukiwanie najkrótszej œcie¿ki
 * Klawisz N - Nowy graf
 * Klawisz O - Wczytaj graf
 * Klawisz S - Zapisz graf
 * Klawisz ESC - Wyjœcie z ka¿dego trybu pracy lub wyjœcie z programu
 */

//Tryby pracy
enum Mode
{
	NONE, //¯aden, mo¿na manipulowaæ wierzcho³kami przeswaj¹c je, wczytaæ plik lub zapisaæ
	ADD_VERTEX, //Dodawanie wierzcho³ków, po klikniêciu w okreœlony punkt pojawia siê tam nowy wierzcho³ek
	ADD_CONNECT, //Dodawanie po³¹czeñ 
	//Mo¿liwe ³¹czenie wierzcho³ków poprzez klikniêcie kolejno na pocz¹tkowy, a potem na koñcowy.
	//Mo¿na ustawiaæ koszt po³¹czenia, w tym celu nale¿y w tym trybie przed po³¹czeniem wierzcho³ków
	//wpisaæ liczbê za pomoc¹ klawiatury. Obecny koszt jest wyœwietlany w komunikacie na spodzie okna.
	REMOVE, //Usuwanie po³¹czeñ
	FIND, //Znajdowanie najkrótszej œcie¿ki
	//Nale¿y kolejno klikn¹æ w wierzcho³ek pocz¹tkowy naszej trasy, a potem w koñcowy, aby sprawdziæ,
	//czy istnieje pomiêdzy nimi po³aczenie i jeœli tak, dana trasa ³¹cz¹ca dane wierzcho³ki zostanie
	//podœwietlona na zielono, a koszt ca³kowity trasy i tekstowa reprezentacja trasy zostanie wyœwietlona
	//w komunikacie na spodzie okna.
};