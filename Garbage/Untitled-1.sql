INSERT ALL
  INTO supplier (S#, sname, status, city) VALUES ('S1', 'Smith', 20, 'London')
  INTO supplier (S#, sname, status, city) VALUES ('S2', 'Jones', 30, 'Paris')
  INTO supplier (S#, sname, status, city) VALUES ('S3', 'Blake', 30, 'Paris')
  INTO supplier (S#, sname, status, city) VALUES ('S4', 'Orhun', 20, 'London')
  INTO supplier (S#, sname, status, city) VALUES ('S5', 'Adams', 30, 'Athens')
SELECT * FROM dual;

INSERT ALL
  INTO part (P#, pname, color, weight, city) VALUES ('P1', 'Nut', 'Red', 12.0, 'London')
  INTO part (P#, pname, color, weight, city) VALUES ('P2', 'Bolt', 'Green', 17.0, 'Paris')
  INTO part (P#, pname, color, weight, city) VALUES ('P3', 'Screw', 'Blue', 17.0, 'Oslo')
  INTO part (P#, pname, color, weight, city) VALUES ('P4', 'Screw', 'Red', 14.0, 'London')
  INTO part (P#, pname, color, weight, city) VALUES ('P5', 'Cam', 'Blue', 12.0, 'Paris')
  INTO part (P#, pname, color, weight, city) VALUES ('P6', 'Cog', 'Red', 19.0, 'London')
SELECT * FROM dual;

INSERT ALL
  INTO sp (S#, P#, QTY) VALUES ('S1', 'P1', 300)
  INTO sp (S#, P#, QTY) VALUES ('S1', 'P2', 200)
  INTO sp (S#, P#, QTY) VALUES ('S1', 'P3', 400)
  INTO sp (S#, P#, QTY) VALUES ('S1', 'P4', 200)
  INTO sp (S#, P#, QTY) VALUES ('S1', 'P5', 100)
  INTO sp (S#, P#, QTY) VALUES ('S1', 'P6', 100)
  INTO sp (S#, P#, QTY) VALUES ('S2', 'P1', 300)
  INTO sp (S#, P#, QTY) VALUES ('S2', 'P2', 400)
  INTO sp (S#, P#, QTY) VALUES ('S2', 'P3', 500)
  INTO sp (S#, P#, QTY) VALUES ('S3', 'P2', 200)
  INTO sp (S#, P#, QTY) VALUES ('S3', 'P3', 200)
  INTO sp (S#, P#, QTY) VALUES ('S3', 'P4', 300)
  INTO sp (S#, P#, QTY) VALUES ('S4', 'P2', 300)
  INTO sp (S#, P#, QTY) VALUES ('S4', 'P3', 400)
SELECT * FROM dual;

CREATE TABLE sp (
    S# CHAR(2) NOT NULL,
    S# CHAR(2) NOT NULL,
    FOREIGN KEY (S#) REFERENCES supplier(supplierId),
    FOREIGN KEY (partId) REFERENCES part(partId),
    qty INTEGER,
    PRIMARY KEY (supplierId,partId)
)
