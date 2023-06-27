-- db creation script for user registration
create schema users;

use users;

create table Users
(
    id int primary key auto_increment,
    username varchar(45) not null,
    password varchar(45) not null
);

insert into Users(username,password) values ('clintEastWood','SomeThingBoutAWoman');