const fs = require('kmake/fsextra');



let project = new Project('LabS3J1');

project.kore = false;
project.cmd = true;

project.addFile('Sources/**');
project.setDebugDir('../Deployment');

fs.copyFileSync(process.cwd()+'/labS3J1/test_input.txt','./Deployment/test_input.txt');
fs.copyFileSync(process.cwd()+'/labS3J1/sorted_input.txt','./Deployment/sorted_input.txt');

resolve(project);
