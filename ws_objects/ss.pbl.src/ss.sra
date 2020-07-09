HA$PBExportHeader$ss.sra
$PBExportComments$Generated Application Object
forward
global type ss from application
end type
global transaction sqlca
global dynamicdescriptionarea sqlda
global dynamicstagingarea sqlsa
global error error
global message message
end forward

global type ss from application
string appname = "ss"
end type
global ss ss

on ss.create
appname = "ss"
message = create message
sqlca = create transaction
sqlda = create dynamicdescriptionarea
sqlsa = create dynamicstagingarea
error = create error
end on

on ss.destroy
destroy( sqlca )
destroy( sqlda )
destroy( sqlsa )
destroy( error )
destroy( message )
end on

