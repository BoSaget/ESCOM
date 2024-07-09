-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jul 09, 2024 at 03:59 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `extra`
--

-- --------------------------------------------------------

--
-- Table structure for table `cursos`
--

CREATE TABLE `cursos` (
  `id` int(11) NOT NULL,
  `nombre` varchar(1000) NOT NULL,
  `apellido` varchar(1000) NOT NULL,
  `direccion` varchar(1000) NOT NULL,
  `telefono` bigint(10) NOT NULL,
  `correo` varchar(1000) NOT NULL,
  `documento` varchar(1000) NOT NULL,
  `nacimiento` date NOT NULL,
  `curso` varchar(1000) NOT NULL,
  `horario` varchar(1000) NOT NULL,
  `pago` varchar(1000) NOT NULL,
  `contrato` bigint(255) NOT NULL,
  `atendido` varchar(1000) NOT NULL,
  `inscripcion` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `cursos`
--

INSERT INTO `cursos` (`id`, `nombre`, `apellido`, `direccion`, `telefono`, `correo`, `documento`, `nacimiento`, `curso`, `horario`, `pago`, `contrato`, `atendido`, `inscripcion`) VALUES
(2, 'Juan', 'Perez', 'And 43', 5544332211, 'l@l.com', 'INe', '2000-04-19', 'Cocina', '10-11AM', 'contado', 3426351, 'Luis', '2024-07-08'),
(4, 'Luis', 'Luz', 'asfasfd', 5544332211, 'l@l.com', 'INE', '2000-04-19', 'Baile', '10-11AM', 'contado', 23423554, 'Juan', '2024-07-08');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `cursos`
--
ALTER TABLE `cursos`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `cursos`
--
ALTER TABLE `cursos`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
