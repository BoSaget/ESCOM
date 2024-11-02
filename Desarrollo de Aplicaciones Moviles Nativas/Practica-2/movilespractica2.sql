-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Oct 28, 2024 at 11:07 PM
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
-- Database: `movilespractica2`
--

-- --------------------------------------------------------

--
-- Table structure for table `roles`
--

CREATE TABLE `roles` (
  `id` int(11) NOT NULL,
  `nombre` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `roles`
--

INSERT INTO `roles` (`id`, `nombre`) VALUES
(1, 'admin'),
(2, 'usuario');

-- --------------------------------------------------------

--
-- Table structure for table `user_model`
--

CREATE TABLE `user_model` (
  `id` bigint(20) NOT NULL,
  `apellido` varchar(255) DEFAULT NULL,
  `contraseña` varchar(255) DEFAULT NULL,
  `correo_usuario` varchar(255) DEFAULT NULL,
  `nombre` varchar(255) DEFAULT NULL,
  `correo` varchar(255) DEFAULT NULL,
  `usuario` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `user_model`
--

INSERT INTO `user_model` (`id`, `apellido`, `contraseña`, `correo_usuario`, `nombre`, `correo`, `usuario`) VALUES
(1, 'Tejeda', '$2a$10$4Zt77KVJRJ1oAhzQbmZNEujMrUtH/9cMUHF7DekSI3MDq6fO3E1FS', NULL, 'Leon', NULL, NULL),
(2, 'Tejeda', '$2a$10$2rsePofuk2uKfMbFjD/C5ugg/THFzEM6pRKAD8uYKHT9HgWjtsBY.', NULL, 'Leon', NULL, NULL),
(3, 'Tejeda', '$2a$10$GqG0/wZ9mPZIg9Av4BFwuuD9l.pOuXyB2bXQRvngkeHJi3WrSNQA.', NULL, 'Leon', 'leont@adm.com', NULL),
(4, 'Tejeda', '$2a$10$012wSePCX9N5S4YiJjmEreC6gr5hiM7P008XmoTuQgAtMdoGTvB5y', NULL, 'Leon', 'leont@adm.com', 'leont'),
(5, 'Tejeda', '$2a$10$OMCvUGApnu/dU2JN.kZ0J.6e3jFpeX1gyddlX.i4TaPjy.1e5Pv0S', NULL, 'Leon', 'leont@adm.com', 'leont'),
(6, 'Tejeda', '12345', NULL, 'Leon', 'leont@adm.com', 'leont'),
(7, 'Tejeda', '$2a$10$sdueut/oR309Fxi3OQ6vqeGRAJKzWPhYdBp4rrQwNuqkygAbHltZi', NULL, 'Leon', 'leont@adm.com', 'leont'),
(8, 'Tejeda', '$2a$10$vUyn0p/09R6GcPZudTOcnuWiyqXkwSlgrQ5vgWD0Jrw0D3M178DXe', NULL, 'Leon', 'leont@adm.com', 'leont'),
(9, 'Tejeda', '$2a$10$p.IGFrbH38x.WrgcsuosJewHBhFo.kd7zctX0/PfmHk3ejnFCFzp6', NULL, 'Leon', 'leont@adm.com', 'leont');

-- --------------------------------------------------------

--
-- Table structure for table `usuarios`
--

CREATE TABLE `usuarios` (
  `id` bigint(20) UNSIGNED NOT NULL,
  `nombre` varchar(255) DEFAULT NULL,
  `apellido` varchar(255) DEFAULT NULL,
  `correo` varchar(255) DEFAULT NULL,
  `usuario` varchar(255) DEFAULT NULL,
  `contraseña` varchar(255) NOT NULL,
  `rol_id` int(11) DEFAULT 2
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `usuarios`
--

INSERT INTO `usuarios` (`id`, `nombre`, `apellido`, `correo`, `usuario`, `contraseña`, `rol_id`) VALUES
(1, 'Leon', 'Tejeda', 'leont@adm.com', 'leont', '$2a$10$uKAxR0/OWDu9cNVr1/Eun.2xz3MS/1MNWWyQWWpNYfUPVQwiOD5py', 2),
(4, 'Prueba', 'Prueba', 'prueba@prueba.com', 'pt', '$2a$10$UmPB5qvJJROHjkTrpVjhM.ShXkiSMdicVCEM/usNgr4MiXTIjBima', 2);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `roles`
--
ALTER TABLE `roles`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `nombre` (`nombre`);

--
-- Indexes for table `user_model`
--
ALTER TABLE `user_model`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `usuarios`
--
ALTER TABLE `usuarios`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `correo` (`correo`),
  ADD UNIQUE KEY `usuario` (`usuario`),
  ADD KEY `rol_id` (`rol_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `roles`
--
ALTER TABLE `roles`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `user_model`
--
ALTER TABLE `user_model`
  MODIFY `id` bigint(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `usuarios`
--
ALTER TABLE `usuarios`
  MODIFY `id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `usuarios`
--
ALTER TABLE `usuarios`
  ADD CONSTRAINT `usuarios_ibfk_1` FOREIGN KEY (`rol_id`) REFERENCES `roles` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
