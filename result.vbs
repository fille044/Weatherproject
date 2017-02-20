Const ForReading = 1
Const ForWriting = 2

Set fso = CreateObject("Scripting.FileSystemObject")
Set com = fso.OpenTextFile("COM5:9600,N,8,1", ForReading)

Set objFSO = CreateObject("Scripting.FileSystemObject")
Set objFile = objFSO.OpenTextFile("C:\Users\denni\Desktop\weatherproject\results.txt", ForWriting, True)

MsgBox("Start to read data from COM")

Do While com.AtEndOfStream <> True
   s = com.ReadLine
   objFile.WriteLine(s)
   WScript.Sleep(200)
Loop

objFile.Close
com.Close()
