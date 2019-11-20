/*
The output of the program is as follows:

Connecting to JDBC...
JDBC connected
Branch table created.

*/

import java.sql.*;
import java.io.*;
import oracle.jdbc.*;
import oracle.sql.*;
import java.util.*;

public class Branch
{	
   public static void main(String[] args) 
   {
      try
      {
         DriverManager.registerDriver
         (new oracle.jdbc.driver.OracleDriver());
         
         System.out.println("Connecting to JDBC...");
         Connection conn = DriverManager.getConnection
	     ("jdbc:oracle:thin:@localhost:1521:xe","fedora","oracle2019");
         System.out.println("JDBC connected.");
         Statement stmt = conn.createStatement();
	 stmt.execute("create table branch (b# char(3) primary key, "+ 
		      "address varchar2(25))");
	 System.out.println("Branch table created.");
	 stmt.close();
	 conn.close();
    }
    catch(Exception e)
    {
      System.out.println("SQL exception: ");
      e.printStackTrace();
      System.exit(-1);
    }
  }
}
