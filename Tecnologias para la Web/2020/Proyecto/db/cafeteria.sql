-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 24, 2024 at 08:25 PM
-- Server version: 10.4.27-MariaDB
-- PHP Version: 8.0.25

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `cafeteria`
--

-- --------------------------------------------------------

--
-- Table structure for table `empleados`
--

CREATE TABLE `empleados` (
  `id` int(11) NOT NULL,
  `rol` varchar(100) NOT NULL,
  `correo` varchar(100) NOT NULL,
  `nombre` varchar(100) NOT NULL,
  `contraseña` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `empleados`
--

INSERT INTO `empleados` (`id`, `rol`, `correo`, `nombre`, `contraseña`) VALUES
(1, 'Admin', '0@pl.com', '0', '0'),
(2, 'Admin', 'nerick@pl.com', 'Nerick', 'c4ca4238a0b923820dcc509a6f75849b'),
(3, 'Admin', 'leila@pl.com', 'Leila', 'c81e728d9d4c2f636f067f89cc14862c'),
(4, 'Admin', 'leon@pl.com', 'Leon', '3f071f4f163d68551f4fc1544c7f69a6'),
(5, 'Cocina', 'c@pl.com', 'Chef 1', 'cbb4581ba3ada1ddef9b431eef2660ce'),
(9, 'Cocina', 'a@pl.com', 'A', '0cc175b9c0f1b6a831c399e269772661');

-- --------------------------------------------------------

--
-- Table structure for table `menu`
--

CREATE TABLE `menu` (
  `id` int(11) NOT NULL,
  `item` varchar(100) NOT NULL,
  `tipo` varchar(1000) NOT NULL,
  `ingredientes` varchar(1000) DEFAULT NULL,
  `notas` varchar(1000) DEFAULT NULL,
  `precio` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `menu`
--

INSERT INTO `menu` (`id`, `item`, `tipo`, `ingredientes`, `notas`, `precio`) VALUES
(1, 'Café Americano\r\n\r\n', 'Bebidas', NULL, 'Sin gluten, vegano, sin lactosa', 35),
(2, 'Café con Leche de Almendras', 'Bebidas', NULL, 'Sin gluten, vegano, sin lactosa', 45),
(4, 'Smoothie de Frutas', 'Bebidas\r\n', NULL, 'Sin gluten, vegano, sin lactosa', 60),
(5, 'Té Verde', 'Bebidas', NULL, 'Sin gluten, vegano, sin lactosa', 25),
(6, 'Tostadas de Aguacate\r\n\r\n', 'Desayunos', 'Pan sin gluten, aguacate, tomate, aceite de oliva, sal y pimienta', 'Sin gluten, vegano, sin lactosa', 75),
(7, 'Bowl de Açaí', 'Desayunos', 'Açaí, plátano, fresas, granola sin gluten, miel (opcional)', 'Sin gluten, vegano (sin miel), sin lactosa', 85),
(8, 'Panqueques de Plátano y Avena', 'Desayunos', 'Avena sin gluten, plátano, leche de almendras, miel de agave', 'Sin gluten, vegano, sin lactosa', 70),
(9, 'Ensalada Mediterránea', 'Almuerzos', 'Quinoa, tomate, pepino, aceitunas, cebolla morada, aceite de oliva, limón', 'Sin gluten, vegano, sin lactosa', 95),
(10, 'Wrap de Vegetales', 'Almuerzos', 'Tortilla sin gluten, hummus, zanahoria, pimientos, espinacas, aguacate', 'Sin gluten, vegano, sin lactosa', 90),
(11, 'Sopa de Lentejas', 'Almuerzos', 'Lentejas, zanahoria, apio, cebolla, ajo, especias', 'Sin gluten, vegano, sin lactosa', 80),
(12, 'Brownie de Chocolate', 'Postres', 'Harina de almendra, cacao, aceite de coco, azúcar de coco', 'Sin gluten, vegano, sin lactosa', 50),
(13, 'Galletas de Avena y Plátano', 'Postres', 'Avena sin gluten, plátano, chispas de chocolate veganas', 'Sin gluten, vegano, sin lactosa', 40),
(14, 'Yogur de Coco con Frutas', 'Postres', 'Yogur de coco, frutas frescas, miel de agave (opcional)', 'Sin gluten, vegano (sin miel), sin lactosa', 55),
(15, 'Café Americano', 'Bebidas Calientes', NULL, NULL, 30),
(16, 'Café con Leche', 'Bebidas Calientes', NULL, NULL, 35),
(17, 'Capuchino', 'Bebidas Calientes', NULL, NULL, 40),
(18, 'Latte', 'Bebidas Calientes', NULL, NULL, 45),
(19, 'Chai Latte', 'Bebidas Calientes', NULL, NULL, 50),
(20, 'Chocolate Caliente', 'Bebidas Calientes', NULL, NULL, 40),
(21, 'Frapuccino de Vainilla', 'Bebidas Frías', NULL, NULL, 60),
(22, 'Smoothie de Frutas', 'Bebidas Frías', NULL, NULL, 55),
(23, 'Té Helado', 'Bebidas Frías', NULL, NULL, 35),
(24, 'Limonada con Hierbabuena', 'Bebidas Frías', NULL, NULL, 30),
(25, 'Agua de Coco', 'Bebidas Frías', NULL, NULL, 40),
(26, 'Tostadas de Aguacate', 'Desayunos', NULL, NULL, 70),
(27, 'Huevos Palomino', 'Desayunos', 'Huevos, espinacas, queso, tomate', NULL, 80),
(28, 'Ensalada César', 'Almuerzos', 'Lechuga, pollo, crutones, queso parmesano, aderezo César', NULL, 90),
(29, 'Wrap de Pollo', 'Almuerzos', 'Tortilla de harina, pollo a la parrilla, lechuga, tomate, mayonesa', NULL, 85),
(30, 'Sándwich de Pavo', 'Almuerzos', 'Pan integral, pavo, queso suizo, lechuga, tomate, mostaza', NULL, 80),
(31, 'Sopa de Tomate', 'Almuerzos', 'Tomates frescos, albahaca, crema', NULL, 70),
(32, 'Cheesecake', 'Postres', NULL, NULL, 60),
(33, 'Galletas de Chispas de Chocolate', 'Postres', NULL, NULL, 35),
(34, 'Muffin de Arándanos', 'Postres', NULL, NULL, 40),
(35, 'Tarta de Manzana', 'Postres', NULL, NULL, 50),
(36, 'Croissant', 'Adicionales', NULL, NULL, 25),
(37, 'Bagel con Queso Crema', 'Adicionales', NULL, NULL, 35),
(38, 'Pan de Plátano', 'Adicionales', NULL, NULL, 35),
(39, 'Prueba', 'Prueba', '', '', 12),
(40, 'Prueba2', 'Prueba', '', '', 15);

-- --------------------------------------------------------

--
-- Table structure for table `usuarios`
--

CREATE TABLE `usuarios` (
  `id` int(11) NOT NULL,
  `correo` varchar(100) NOT NULL,
  `telefono` bigint(10) DEFAULT NULL,
  `nombre` varchar(100) DEFAULT NULL,
  `contraseña` varchar(100) NOT NULL,
  `rango` int(1) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `usuarios`
--

INSERT INTO `usuarios` (`id`, `correo`, `telefono`, `nombre`, `contraseña`, `rango`) VALUES
(1, '1@1.com', 1111111111, NULL, 'c4ca4238a0b923820dcc509a6f75849b', 0),
(2, 'a@a.com', 22222222, 'Aaa', '0cc175b9c0f1b6a831c399e269772661', 0),
(4, 'b@b.com', 33333333, '', '92eb5ffee6ae2fec3ad71c777531578f', 1);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `empleados`
--
ALTER TABLE `empleados`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `menu`
--
ALTER TABLE `menu`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `usuarios`
--
ALTER TABLE `usuarios`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `empleados`
--
ALTER TABLE `empleados`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `menu`
--
ALTER TABLE `menu`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=44;

--
-- AUTO_INCREMENT for table `usuarios`
--
ALTER TABLE `usuarios`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
