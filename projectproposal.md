# Knox County Water Project Proposal

## Organization Information:
### Mount Vernon Department of Water
-Engineer Brian Ball (740)-393-9528
-Utilities Director Mathias Orndorf (740) 358-6112
-Auditor Terry Scott
-Dynamic Networks rep Joe "Snoffsnyder"

## Description of Needs:
The Mount Vernon Department of Water need a read-only archival access system to help facilitate the departments transition between system providers. They are currently using CMI's UtyX and will only be able to bring the past 3 years of customer data with them. The organization would like us to develop a database where one could search by address or unique account number and pull up all relevant information, specifically billing history and text file comment that are attached to each account. There needs to be standard availability as well as an emphasis on security.

If there is extra time they would like a report generation function that can return all relevant fields either as a .csv, .psv, .tsv, or a .txt document.

## Description of Data Storage and Processing:
We will utilize a MySQL database, locally hosted on the virtual machine that the software is running on.
We intend to use C++14 for our back-end, and use HTML/CSS/JS for our front end.
