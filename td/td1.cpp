/*
 * Cursus CentraleSupélec - Dominante Informatique et numérique - Campus de Paris-Saclay
 * 3IF1020 – Ateliers de programmation et outils de développement - TD n°1
 * https://wdi.centralesupelec.fr/3IF1020/ProgTD1
 *
 * c++ -std=c++20 -o td1 td1.cpp
 * ./td1
 */


#include <iostream>
#include <cmath>
#include <functional>
#include <numbers>



// Définir une fonction qui calcule et retourne la valeur de 𝑓 en 𝑥
double sin_x_plus_cos_sqrt2_times_x( double x )
{
    return sin( x ) + cos( std::numbers::sqrt2 * x) ;
}

void print_function(double x) {
    std::cout << "sin_x_plus_cos_sqrt2_times_x( " << x << " ) = "
    << sin_x_plus_cos_sqrt2_times_x( x ) << std::endl;
}


// Définir une fonction test_11() qui appelle la précédente avec 1 puis avec -4.5 comme
// argument, et qui affiche les résultats retournés.
void test_11()
{
    std::cout << "test_11: " << std::endl;
    print_function(1); 
    print_function(-4.5) ;
}

// Définir une fonction test_12() qui demande une valeur à l'utilisateur, appelle la
// fonction sin_x_plus_cos_sqrt2_times_x() avec la valeur fournie par l'utilisateur
// comme argument et affiche le résultat retourné. 
void test_12()
{
    std::cout << "test_12:\n";
    double user_value;
    std::cin >> user_value;
    std::cout << "Valeur : "<< user_value << "\n";
    print_function(user_value);
}

// Définir une fonction test_21() qui demande une valeur à l'utilisateur, et affiche le
// résultat de l'appel de la fonction sin_x_plus_cos_sqrt2_times_x() pour 10 valeurs
// espacées de 1 en commençant avec la valeur fournie par l'utilisateur.
// Vous utiliserez une boucle for avec une variable de boucle commençant à 0.
void test_21()
{
    std::cout << "test_21:\n";
    double user_value;
    std::cout << "Valeur initiale : ";
    std::cin >> user_value;
    for( int i = 0; i < 10; i++ )
    {
        print_function(user_value + i);
    }
    std::cout << std::endl;
}

// Définir une fonction qui affiche le résultat de la fonction sin_x_plus_cos_sqrt2_times_x()
// pour toutes les valeurs entre begin et end avec un pas de step. 
void print_sin_x_plus_cos_sqrt2_times_x( double begin, double end, double step )
{
    for( double x = begin; x <= end; x += step )
    {
        print_function(x);
    }
}

// Définir une fonction test_22() qui appelle la précédente avec -10, 10 et 2 comme arguments
void test_22()
{
    std::cout << "test_22:\n";
    print_sin_x_plus_cos_sqrt2_times_x(-10, 10, 2);
    std::cout << std::endl;
}


// Définir une fonction test_23() qui demande à l'utilisateur une borne basse, une borne
// haute (qui devra être supérieure à la borne basse) et un nombre de valeurs à afficher,
// puis appelle la fonction print_sin_x_plus_cos_sqrt2_times_x() pour afficher les valeurs
// demandées. 
// Vous utiliserez une instruction if pour vérifier que la borne haute donnée par l'utilisateur
// est strictement supérieure à la borne basse, et une instruction while pour refaire une
// demande en cas de test négatif ; vous ferez de même pour vérifier qu'au moins 2 valeurs
// sont demandées. 
void test_23()
{
    std::cout << "test_23: \n";
    double begin, end;
    int number_of_values;
    bool is_valid1 = false;
    bool is_valid2 = false;

    std::cout << "Borne basse : ";
    std::cin >> begin;

    while (!is_valid1 || !is_valid2) {

        if (!is_valid1){
        std::cout << "Borne haute : ";
        std::cin >> end;
        

        if (end <= begin) {
            std::cout << "Erreur : la borne haute doit être plus grande que la borne basse\n";
            continue;
        }
        else {
            is_valid1 = true;
        }
        }
        else {
            std::cout << "Nombre de valeurs : ";
            std::cin >> number_of_values;

            if (number_of_values < 2) {
                std::cout << "Erreur : le nombre de valeurs doit être au minimum 2\n";
                continue;
            }
            else {
                is_valid2 = true;
        }
    }
}

    print_sin_x_plus_cos_sqrt2_times_x(begin, end, (end - begin) / (number_of_values - 1));

}

// Définir une fonction qui retourne la valeur estimée de la dérivée de la fonction func en x
double compute_derivative( std::function< double( double ) > func, double x, double epsilon )
{
    return ( func( x + epsilon ) - func( x ) ) / epsilon;
}

void print_function2(double x, double epsilon) {
    std::cout << "derivative of sin_x_plus_cos_sqrt2_times_x( " << x << " ) = "
    << compute_derivative(sin_x_plus_cos_sqrt2_times_x, x, epsilon) << std::endl;
}
// Définir une fonction test_31() qui affiche l'estimation de la dérivée de
// sin_x_plus_cos_sqrt2_times_x() dans l'intervalle [-4.6, -4.5] par pas de 0.01 avec une
// valeur d'epsilon égale à 10-5. 

void print_derivee_sin_x_plus_cos_sqrt2_times_x( double begin, double end, double step, double epsilon )
{
    for( double x = begin; x <= end; x += step )
    {
        print_function2(x, epsilon);
    }
}

void test_31()
{
    std::cout << "test_31:\n";
    print_derivee_sin_x_plus_cos_sqrt2_times_x(-4.6, -4.5, 0.01, 1e-5);

}

// Définir une fonction qui retourne un nombre compris dans l'intervalle [begin, end] pour
// lequel le résultat de l'appel de func sur ce nombre est inférieur en valeur absolue à
// precision.
// Cette fonction a pour précondition que func( begin ) et func( end ) sont de signes
// opposés ; si cette précondition n'est pas vérifiée, la fonction retournera 0.
// Vous procéderez par dichotomie.
double find_zero( std::function< double( double ) > func, double begin, double end, double precision )
{
    double middle = (begin + end) / 2;

    while ( std::abs(func(middle)) >= precision ) {
        if (func(middle) * func(begin) < 0) {
            end = middle;
        }
        else {
            begin = middle;
        }

        if ( ( begin + end ) / 2 == begin || ( begin + end ) / 2 == end ) {
            return NAN;
        }

        middle = (begin + end) / 2;

    }
    return middle;
}

// Définir une fonction test_32() qui cherche un zéro de la fonction sin_x_plus_cos_sqrt2_times_x()
// dans l'intervalle [-2, 0] avec une précision de 10-5
void test_32()
{
    std::cout << "test_32:\n";
    double zero = find_zero(sin_x_plus_cos_sqrt2_times_x, -2, 0, 1e-5);
    if (zero == NAN) {
        std::cout << "Aucun zéro trouvé\n";
    }
    else {
        print_function(zero);
    }

}

// Définir une fonction qui cherche dans chaque intervalle de largeur width (de la forme
// [begin + n * width, begin + (n + 1) * width] où n est un naturel quelconque), sans
// dépasser end comme borne haute, un nombre pour lequel le résultat de l'appel de func
// est inférieur en valeur absolue à precision ; au maximum, max_number_of_results seront
// retournés dans le tableau results ; la fonction a pour résultat le nombre exact de
// valeurs présentes dans results.
int find_all_zeros( std::function< double( double ) > func, double begin, double end, double width,
                    double precision, double results[], double max_number_of_results )
{
    int number_of_results = 0;
    for (int i = 0; number_of_results < max_number_of_results;  i++) {
        if (begin + (i + 1) * width <= end) {
            double zero = find_zero(func, begin + i * width, begin + (i + 1) * width, precision);
            // check if zeeo is a number
            if ( !std::isnan(zero) ) {
                results[number_of_results] = zero;
                number_of_results++;
            }
        }
        else {
            break;
        }
    }
    return number_of_results;
}

// Définir une fonction test_41() qui cherche les zéros de la fonction
// sin_x_plus_cos_sqrt2_times_x() dans l'intervalle [-10, 10], avec une largeur de 0.5,
// une précision de 10-5 et un maximum de 10 zéros retournés. 
void test_41()
{
    std::cout << "test_41:\n";
    double results[10];
    int number_of_results = find_all_zeros(sin_x_plus_cos_sqrt2_times_x, -10, 10, 0.5, 1e-5, results, 10);
    for (int i = 0; i < number_of_results; i++) {
        print_function(results[i]);
    }
}

// Définir une fonction qui cherche dans chaque intervalle de largeur width (de la forme
// [begin + n * width, begin + (n + 1) * width] où n est un naturel quelconque), sans
// dépasser end comme borne haute, un extrema de func, un extrema étant défini comme un
// nombre pour lequel la valeur estimée (calculée en utilisant epsilon) de la dérivée de
// func en ce nombre est inférieur en valeur absolue à precision ; au maximum,
// max_number_of_results seront retournés dans le tableau results ; la fonction a pour
// résultat le nombre exact de valeurs présentes dans results.
int find_all_extrema( std::function< double( double ) > func, double begin, double end, double width,
                      double precision, double epsilon, double results[], double max_number_of_results )
{
   auto derivative = [func, epsilon](double x) {
        return compute_derivative(func, x, epsilon);
    };
    return find_all_zeros(derivative, begin, end, width, precision, results, max_number_of_results);
}

// Définir une fonction test_42() qui cherche les extrema de la fonction sin_x_plus_cos_sqrt2_times_x()
// dans l'intervalle [-10, 10], avec une largeur de 0.5, une précision de 10-5, une dérivée
// estimée en utilisant 10-5 pour epsilon et un maximum de 10 extrema retournés. 
void test_42()
{
    std::cout << "test_42:\n";
    double results[10];
    int number_of_results = find_all_extrema(sin_x_plus_cos_sqrt2_times_x, -10, 10, 0.5, 1e-5, 1e-5, results, 10);
    for (int i = 0; i < number_of_results; i++) {
        print_function(results[i]);
    }
}


int main()
{
    // test_11();
    // test_12();
    // test_21();
    // test_22();
    // test_23();
    // test_31();
    // test_32();
    // test_41();
    test_42();
}
