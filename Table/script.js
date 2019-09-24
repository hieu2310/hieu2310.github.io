var count, table = document.querySelector(".table");
// Xóa các hàng
for(let i=1 ; i<table.rows.length ; i++){
    table.rows[i].cells[5].onclick = function(){
        var test = confirm("Do you want to delete");
        if(test == true){
            count = this.parentElement.rowIndex;
            table.deleteRow(count);
        }
    };
}

// Sắp xếp lại các cột theo thứ tự bé đến lớn
for(let j=0 ; j<table.rows[0].cells.length-1; j++){
    table.rows[0].cells[j].onclick = function(){
        var z = [], countArr = 0;
        count = this.cellIndex;
        for(let k=1 ; k<table.rows.length ; k++){
            z[countArr] = table.rows[k].cells[count].innerHTML; // Get information in table html
            countArr ++ ;
        }
        z.sort();
        // console.log(z);
        for(var l=1 ; l<table.rows.length ; l++){
            for(var m=0; m<table.rows.length-1;m++){
                if(table.rows[l].cells[count].innerHTML == z[m]){
                    var a = "";
                    a = table.rows[l].innerHTML;
                    table.rows[l].innerHTML = table.rows[m+1].innerHTML;
                    table.rows[m+1].innerHTML = a;
                } 
            }
        }
    } 
}
