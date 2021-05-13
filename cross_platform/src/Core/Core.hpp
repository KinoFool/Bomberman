/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <functional>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <fstream>
#include <memory>
#include <utility>
#include "Raylib/XRay/XRay.hpp"
#include "IGraphical.hpp"

class Core {

    public:
        /**
         * @brief Construct a new Core object
         */
        Core();

        /**
         * @brief Destroy the Core object
         */
        ~Core();

        /**
         * @brief Run the core
         *
         * @return A int ( SUCCESS OR FAILED )
         */
        int run();

    private:
        std::shared_ptr<IGraphical> _graphical;
};

#endif /* !CORE_HPP_ */