import os

print("Checking for and removing existing reports...")
if os.path.exists("errorreport.md"):
    os.remove("errorreport.md")
else:
    print("NOTE: No previous error report markdown found to delete.\n")

if os.path.exists("notereport.md"):
    os.remove("notereport.md")
else:
    print("NOTE: No previous notes repoort markdown found to delete. \n")

print("Creating new reports...")
notesfile = open("notereport.md", "w+")
errorfile = open("errorreport.md", "w+")

print("Searching output.txt...")
with open("./build/tmp/compileFrcUserProgramLinuxathenaDebugExecutableFrcUserProgramCpp/output.txt") as file:
    search = file.readlines()

print("Writing error report...")
for i, line in enumerate(search):
    if "error:" in line:
        errorfile.write("<br> <br> \n***\n <br>  ")
        for l in search[i:i+3]: 
            errortowrite = l.replace("error:","<br> **ERROR:** <br>")
            errortowrite = errortowrite.replace("[-","<br>[-")
            errorfile.write(errortowrite)

print("Writing Notes report...")
for i, line in enumerate(search):
    if "note:" in line:
        notesfile.write("<br> <br> \n***\n <br>  >")
        for m in search[i:i+3]: 
            towrite = m.replace("note:","<br> **NOTE:** <br>")
            towrite = towrite.replace("[-","<br>[-")
            notesfile.write(towrite)
    