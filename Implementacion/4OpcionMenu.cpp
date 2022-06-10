/*ESPE
*Enunciado del problema:
*   Realizar el codigo de la catedra en clases (POO)
*Autor 
* Camila Rivera
* Christian Román
*Fecha de creacion
*   10-06-2022
*Fecha de modificacion
*   10 - 06 -2022
*Grupo #2
*Github del grupo:
* https://github.com/Grupo8-4698-EstructuraDeDatos/4698-Grupo8-EstructuradeDatos
*/
#include "4OpcionMenu.h"

/**
 * MenuOption::MenuOption(std::string label, MenuOptionCallback callback) {
 *     esto->etiqueta = etiqueta;
 *     this->devolución de llamada = devolución de llamada;
 * }
 * 
 * Parameters
 * ----------
 * label : string
 * 	El texto que se mostrará en la opción de menú.
 * callback : MenuOptionCallback
 * 	Un puntero de función a una función que no toma parámetros y devuelve void.
 */
MenuOption::MenuOption(std::string label, MenuOptionCallback callback) {
    this->label = label;
    this->callback = callback;
}

/**
 * Es un constructor para la clase MenuOption.
 * 
 * Parameters
 * ----------
 * label : string
 * 	El texto que se mostrará en el menú.
 * callback : MenuOptionCallback
 * 	La función a llamar cuando se selecciona la opción.
 * wait_after_exec : bool
 * 	Si es verdadero, el menú esperará a que el usuario presione una tecla después de ejecutar la
 * devolución de llamada.
 */
MenuOption::MenuOption(std::string label, MenuOptionCallback callback, bool wait_after_exec) {
    this->label = label;
    this->callback = callback;
    this->wait_after_exec = wait_after_exec;
}

/**
 * Es un constructor para la clase MenuOption.
 * 
 * Parameters
 * ----------
 * label : string
 * 	El texto que se mostrará en el menú.
 * callback : MenuOptionCallback
 * 	Un puntero de función a la función que se llamará cuando se seleccione la opción de menú.
 * arguments : MenuOptionArguments
 * 	Este es un puntero a una estructura MenuOptionArguments. Esta estructura contiene los argumentos
 * que se pasarán a la función de devolución de llamada.
 */
MenuOption::MenuOption(std::string label, MenuOptionCallback callback, MenuOptionArguments arguments) {
    this->label = label;
    this->callback = callback;
    this->arguments = arguments;
}

/**
 * Es un constructor para la clase MenuOption.
 * 
 * Parameters
 * ----------
 * label : string
 * 	El texto que se mostrará en el menú.
 * callback : MenuOptionCallback
 * 	La función a llamar cuando se selecciona la opción.
 * arguments : MenuOptionArguments
 * 	Este es un puntero a una estructura MenuOptionArguments. Esta estructura se define de la siguiente
 * manera:
 * wait_after_exec : bool
 * 	Si es verdadero, el menú esperará a que el usuario presione una tecla después de ejecutar la
 * devolución de llamada.
 */
MenuOption::MenuOption(std::string label, MenuOptionCallback callback, MenuOptionArguments arguments, bool wait_after_exec) {
    this->label = label;
    this->callback = callback;
    this->arguments = arguments;
    this->wait_after_exec = wait_after_exec;
}

/**
 * Devuelve la etiqueta de la opción de menú.
 * 
 * Returns
 * -------
 * 	La etiqueta de la opción de menú.
 */
std::string MenuOption::get_label() {
    return label;
}

/**
 * La función toma un puntero a una función que toma un vector de cadenas y devuelve vacío
 */
void MenuOption::execute() {
    callback(arguments);
}

/**
 * Devuelve un valor booleano que indica si la opción del menú debe esperar o no después de que se haya
 * ejecutado.
 * 
 * Returns
 * -------
 * 	El valor de la variable wait_after_exec.
 */
bool MenuOption::should_wait() {
    return wait_after_exec;
}

/**
 * Devuelve una referencia al objeto arguments.
 * 
 * Returns
 * -------
 * 	Una referencia al objeto arguments.
 */

MenuOptionArguments &MenuOption::get_args() {
    return arguments;
}