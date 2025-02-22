const fs = require('fs');

let project = new Project('LabS4J2');

project.kore = false;
project.cmd = true;

project.addFile('Sources/**');
project.setDebugDir('../Deployment');

fs.copyFileSync(process.cwd()+'/labS4J2/test_input.txt','./Deployment/test_input.txt');

resolve(project);
