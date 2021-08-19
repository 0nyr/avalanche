#pragma once

#include <list>
#include "SFML/Graphics.hpp"
#include "../../inc/logic/Eventable.hpp"
#include "../../inc/gui/UIObject.hpp"

/** This object basically manages all the events
 * 
 */
class EventHandler {
    private:
        sf::RenderWindow & window;
        std::string message;

    public:
        EventHandler(sf::RenderWindow & window);
        ~EventHandler() = default;

        /* [ C++ templating and linking ] [troubleshooting]

        """
        A template is not a class or a function. A template is a “pattern” 
        that the compiler uses to generate a family of classes or functions.
        """

        I had the following error:
        """
        /home/onyr/Documents/code/matthieu/avalanche/src/gui/App.cpp:55: 
        undefined reference to '
        void EventHandler::handleEvents<UIObject>(
            std::__cxx11::list<UIObject*, std::allocator<UIObject*> >
        )'
        """
        
        I spent way to much time realizing the error I had was because
        the template function must be declared and defined both in the header
        file (for general cases). 
        
        The exception is if you already know (read StackOverflow question example)
        how the template will be created. In this situation it is possible to
        create by hand the instantiated templated in the .cpp file. This
        can be useful if the different codes are different. Otherwise there going
        to be code duplication and it should be avoided.

        Read the StackOverflow and ISO Cpp references for more details.

            StackOverflow: https://stackoverflow.com/questions/115703/storing-c-template-function-definitions-in-a-cpp-file 
            ISO Cpp: https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl

        NOTE: Distinguish template classes:

            template<typename T>
            class Foo {
                private:
                    T x;

                public:
                    Foo();
                    void someMethod(T x);
            };

        from template functions:

            template<typename T>
            void foo()
            {
                std::cout << "Here I am!\n";
            }

        INFO: Here, we are dealing with a template member function since we
        don't want to have a different instance of EventHandler to handle
        the different Eventable lists.
        */

        /** This function is responsible for calling the necessary functions so
         * as to handle events of a list of Eventable objects.
         * 
         * @param eventables - A list of pointers of Eventable objects.
         */
        template<typename T>
        void handleEvents(std::list<T *> eventables)
        {
            // check all the window's events that were triggered 
            // since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // check general events
                switch (event.type)
                {
                    // window closed
                    case sf::Event::Closed:
                        window.close();
                        break;

                    // we don't process other types of events
                    default:
                        break;
                }

                // check drawables events
                for (Eventable * eventable : eventables) {
                    eventable->handleEvents(event);
                }

            }
        }
        
        
};