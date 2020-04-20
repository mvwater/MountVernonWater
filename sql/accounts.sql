-- phpMyAdmin SQL Dump
-- version 4.6.6deb5
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Mar 29, 2020 at 04:39 PM
-- Server version: 5.7.29-0ubuntu0.18.04.1
-- PHP Version: 7.2.24-0ubuntu0.18.04.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `mvwater`
--

-- --------------------------------------------------------

--
-- Table structure for table `accounts`
--

CREATE TABLE `accounts` (
  `AccountNo` varchar(8) NOT NULL,
  `AcctStatus` varchar(1) DEFAULT NULL,
  `SrtDate` varchar(10) DEFAULT NULL,
  `TName` varchar(20) DEFAULT NULL,
  `TAdd1` varchar(26) DEFAULT NULL,
  `TAdd2` varchar(27) DEFAULT NULL,
  `TAdd3` varchar(10) DEFAULT NULL,
  `TPhone` varchar(12) DEFAULT NULL,
  `TEmail` varchar(31) DEFAULT NULL,
  `TCity` varchar(12) DEFAULT NULL,
  `TState` varchar(2) DEFAULT NULL,
  `TZip` varchar(5) DEFAULT NULL,
  `TSScan` varchar(10) DEFAULT NULL,
  `TDL#` varchar(10) DEFAULT NULL,
  `TCell#` varchar(10) DEFAULT NULL,
  `TDoB` varchar(10) DEFAULT NULL,
  `LName` varchar(20) DEFAULT NULL,
  `LAdd1` varchar(15) DEFAULT NULL,
  `LAdd2` varchar(10) DEFAULT NULL,
  `LAdd3` varchar(10) DEFAULT NULL,
  `LPhone` varchar(10) DEFAULT NULL,
  `LEmail` varchar(35) DEFAULT NULL,
  `LCity` varchar(12) DEFAULT NULL,
  `LSt` varchar(2) DEFAULT NULL,
  `LZip` varchar(5) DEFAULT NULL,
  `LSScan` varchar(10) DEFAULT NULL,
  `LDL#` varchar(10) DEFAULT NULL,
  `LDoB` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `accounts`
--

INSERT INTO `accounts` (`AccountNo`, `AcctStatus`, `SrtDate`, `TName`, `TAdd1`, `TAdd2`, `TAdd3`, `TPhone`, `TEmail`, `TCity`, `TState`, `TZip`, `TSScan`, `TDL#`, `TCell#`, `TDoB`, `LName`, `LAdd1`, `LAdd2`, `LAdd3`, `LPhone`, `LEmail`, `LCity`, `LSt`, `LZip`, `LSScan`, `LDL#`, `LDoB`) VALUES
('01-97-3', 'A', '05-12-1980', 'Marline Pentin', '175 Red Cloud Center', '3782 Aberg Junction', NULL, '366-122-8380', 'mpentin18@meetup.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '47 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('03-02-4', 'A', '08-29-2017', 'Shayne Smolan', '7223 Moulton Circle', NULL, NULL, '104-957-8948', 'ssmolan5@google.de', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '8 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('03-45-2', 'I', '02-26-2019', 'Nikolai Rushman', '63 Miller Pass', '65398 Carpenter Plaza', NULL, '308-771-6797', 'nrushman17@woothemes.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '46 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('03-46-3', 'A', '01-19-2002', 'Kessia Wride', '37 Milwaukee Pass', NULL, NULL, '115-115-9912', 'kwride1c@over-blog.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '51 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('04-11-1', 'I', '07-18-1980', 'Kerr Plues', '59 6th Point', NULL, NULL, '238-870-9912', 'kplues6@examiner.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '9 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('05-53-9', 'A', '10-30-1973', 'Reagan Stormont', '72543 Del Sol Road', NULL, NULL, '947-416-8624', 'rstormont8@hubpages.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '11 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('06-13-4', 'A', '07-26-1998', 'Kailey Petrelli', '37952 Hovde Park', NULL, NULL, '548-992-2766', 'kpetrellis@hugedomains.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '31 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('06-73-2', 'A', '11-14-2009', 'Jemimah Dreamer', '5606 Talisman Road', '1 Scoville Place', NULL, '289-207-6772', 'jdreamer16@ted.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '45 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('08-56-6', 'I', '04-22-2003', 'Boigie Playfair', '1 Cardinal Court', NULL, NULL, '210-117-7125', 'bplayfair1b@phoca.cz', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '50 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('09-83-3', 'A', '08-03-1986', 'Terencio Piper', '21 Elgar Prkwy', NULL, NULL, '686-822-4208', 'tpipern@arizona.edu', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '26 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('10-59-1', 'I', '12-11-1977', 'Reinald Mallinar', '194 Orin Terrace', NULL, NULL, '403-680-9704', 'rmallinarm@theglobeandmail.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '25 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('104-23-1', 'A', '08-31-2013', 'Fraze Tanby', '85 Delaware Prk', NULL, NULL, '993-242-3046', 'ftanby0@dedecms.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '3 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('15-94-6', 'A', '02-07-1984', 'Orly Shaughnessy', '187 Kropf Terrace', NULL, NULL, '715-997-8701', 'oshaughnessyu@homestead.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '33 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('16-18-6', 'I', '07-25-2002', 'Brien Lodevick', '77424 Vahlen Parkway', NULL, NULL, '567-429-4493', 'blodevick12@reverbnation.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '41 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('18-86-1', 'A', '01-22-2012', 'Kori Alstead', '1 Florence Hill', NULL, NULL, '245-225-4126', 'kalsteadb@quantcast.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '14 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('19-27-1', 'A', '05-18-1999', 'Edan Drust', '0759 Glacier Hill Park', NULL, NULL, '475-973-0609', 'edrust9@stumbleupon.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '12 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('23-60-8', 'A', '02-02-1973', 'Joanne Gorring', '37701 Bonner Hill', NULL, NULL, '497-228-0000', 'jgorringd@tmall.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '16 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('24-18-1', 'A', '01-02-1995', 'Bria Klimshuk', '61907 Merry Plaza', NULL, NULL, '447-784-5872', 'bklimshuk19@examiner.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '48 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('24-43-4', 'I', '02-15-2005', 'Rozina Church', '9924 Lyons Park', '9148 Sachs Park', NULL, '485-528-9798', 'rchurchg@jiathis.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '19 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('24-92-7', 'A', '02-09-1999', 'Hart Vanns', '6284 Browning Plaza', NULL, NULL, '855-131-7503', 'hvanns1@macromedia.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '4 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('25-70-5', 'I', '01-11-2005', 'Caroline Dogg', '1 Parkside Pass', NULL, NULL, '287-404-4680', 'cdoggq@nifty.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '29 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('29-58-2', 'A', '09-09-2009', 'Teena Frandsen', '1627 Drewry Ln', NULL, NULL, '223-260-3035', 'tfrandsenl@slideshare.net', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '24 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('36-80-8', 'A', '09-21-2008', 'Cesare Coverly', '00 Waubesa Way', NULL, NULL, '373-443-3787', 'ccoverlye@goodreads.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '17 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('39-82-3', 'A', '09-08-2013', 'Roxanna Colloff', '0177 Donald Street', NULL, NULL, '349-247-5315', 'rcolloffv@addtoany.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '34 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('4-05-1', 'I', '02-18-1997', 'Bonny Clemenzo', '0 Cottonwood Parkway', NULL, NULL, '747-918-1119', 'bclemenzoa@businesswire.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '13 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('43-36-1', 'A', '08-01-1990', 'Ruthann Tretwell', '3 Melby Court', NULL, NULL, '765-702-4202', 'rtretwell11@csmonitor.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '40 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('45-76-9', 'A', '12-22-2007', 'Mehetabel Dicke', '114 Fair Oaks Terrace', NULL, NULL, '626-243-6113', 'mdickey@nasa.gov', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '37 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('48-44-5', 'A', '01-12-1991', 'Dolf O\'Hickey', '40 Straubel Place', NULL, NULL, '568-860-8325', 'dohickeyr@noaa.gov', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '30 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('5-76-8', 'A', '11-11-2016', 'Edna Pearcey', '39 Nancy Way', NULL, NULL, '126-542-0726', 'epearcey1a@t-online.de', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '49 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('51-94-1', 'I', '10-02-1983', 'Philippa Malyan', '40 Armistice Way', NULL, NULL, '112-492-0137', 'pmalyanx@pbs.org', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '36 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('53-71-8', 'A', '07-05-1983', 'Valdemar Reeve', '04 Farmco Pass', NULL, NULL, '272-951-6319', 'vreeve15@dyndns.org', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '44 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('57-76-1', 'A', '12-03-1981', 'Shannan De Marchi', '8 Gerald Crossing', NULL, NULL, '876-146-0041', 'sde7@squidoo.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '10 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('58-61-2', 'A', '06-01-2019', 'Skell Dregan', '88 Bay Way', NULL, NULL, '119-210-4458', 'sdregan10@homestead.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '39 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('61-82-8', 'A', '07-18-2012', 'Arlen Garnsworth', '582 Village Green Road', NULL, NULL, '829-176-4391', 'agarnsworthc@homestead.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '15 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('62-04-6', 'A', '09-20-1999', 'Kyle Westgarth', '45 Jana Alley', NULL, NULL, '810-560-6957', 'kwestgarthh@blogspot.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '20 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('63-94-5', 'A', '12-09-2009', 'Babita Manley', '15536 Transport Pass', NULL, NULL, '257-103-3012', 'bmanleyi@miibeian.gov.cn', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '21 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('69-31-1', 'A', '05-08-2019', 'Alleyn Rodders', '55112 Bonner Rd', NULL, NULL, '672-795-0029', 'aroddersk@twitter.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '23 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('70-14-3', 'A', '02-14-2019', 'Lilas Egan', '84 Loftsgordon Hill', '87859 Cody Road', NULL, '509-706-0594', 'leganj@nationalgeographic.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '22 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('71-83-1', 'A', '01-28-1987', 'Haleigh Segeswoeth', '3 Waubesa Point', NULL, NULL, '728-683-2067', 'hsegeswoetho@angelfire.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '27 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('73-43-3', 'A', '08-05-2010', 'Beckie Boylund', '5 Vera Parkway', NULL, NULL, '695-500-0631', 'bboylundw@example.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '35 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('74-63-6', 'A', '08-07-2008', 'Nathalie Episcopio', '71304 Pierstorff Center', NULL, NULL, '405-132-1688', 'nepiscopio4@cnbc.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '7 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('74-73-3', 'A', '12-23-2008', 'Blinni Miles', '5410 Summit Hill', NULL, NULL, '116-307-5238', 'bmilesf@geocities.jp', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '18 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('75-58-8', 'A', '06-08-2012', 'Dulcie MacTrustrie', '69958 American Ash Terrace', NULL, NULL, '362-402-2281', 'dmactrustrie13@sciencedaily.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '42 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('79-20-4', 'A', '01-23-1992', 'Constanta Paike', '862 Longview Terrace', NULL, NULL, '471-632-6451', 'cpaikez@homestead.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '38 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('79-43-3', 'A', '09-13-2015', 'Wynne Wannop', '059 Golf View Parkway', '86901 Lakewood Gardens Park', NULL, '211-576-2361', 'wwannop14@comsenz.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '43 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('80-90-8', 'A', '12-27-1987', 'Sonny Trevarthen', '53 Katie Terrace', NULL, NULL, '974-637-4026', 'strevarthenp@toplist.cz', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '28 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('80-98-7', 'A', '01-21-1979', 'Bobette Queenborough', '7046 Chive Center', NULL, NULL, '115-257-0631', 'bqueenborough3@ning.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '6 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('83-48-1', 'A', '10-01-1999', 'Kennedy Tuffell', '02 Lighthouse Bay Park', NULL, NULL, '833-433-7925', 'ktuffellt@shutterfly.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '32 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL),
('83-77-4', 'A', '06-30-1983', 'Cherri Ivetts', '26920 Springs St', NULL, NULL, '829-242-5669', 'civetts2@friendfeed.com', 'MOUNT VERNON', 'OH', '43050', NULL, '', NULL, NULL, 'CITY OF MOUNT VERNON', '5 N GAY STREET', '', '', '', 'waterclkaccting@mountvernonohio.org', 'MOUNT VERNON', 'OH', '43050', '', '', NULL);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `accounts`
--
ALTER TABLE `accounts`
  ADD PRIMARY KEY (`AccountNo`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
