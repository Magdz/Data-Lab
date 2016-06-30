function Upload(){
	var file = document.getElementById("fileID").files[0];
	if (file) {
	    var reader = new FileReader();
	    reader.readAsText(file, "UTF-8");
	    reader.onload = function (evt) {
	        document.getElementById("fileContents").innerHTML = evt.target.result;
	    }
	    reader.onerror = function (evt) {
	        document.getElementById("fileContents").innerHTML = "error reading file";
	    }
	}
}