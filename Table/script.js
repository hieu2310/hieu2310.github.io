/*var count,table = document.querySelector(".table");
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
}*/

let students = [
    // Nhập thông tin học viên
    {
        name: 'Tran Duc Hieu',
        birthYear: 2000,
        email: 'hieu2000@gmail.com',
        phone: '02000'
    },

    {
        name: 'Dinh Nhi Ha',
        birthYear: 1973,
        email: 'hadn1973@gmail.com',
        phone: '01973'
    },

    {
        name: 'Tran Thanh Nam',
        birthYear: 1972,
        email: 'namtt1972@gmail.com',
        phone: '01972'
    },

    {
        name: 'Tran Ha Chinh',
        birthYear: 2004,
        email: 'tranght2004@gmail.com',
        phone: '02004'
    }
];

function renderContent(){
    // Đưa thông tin học viên ra ngoài màn hình
    let contentHtml = '';
    
    for(let i =0; i<students.length; i++){
        const a = students[i];
        contentHtml += `
            <tr>
                <td>${a.name}</td>
                <td>${a.birthYear}</td>
                <td>${a.email}</td>
                <td>${a.phone}</td>
                <td>
                    <a href="javascript:void(0)" class="text-danger1" onclick="addUser(${i}, this)"><span class = "add"><i class="far fa-edit"></i><span class = "text_add"> Chỉnh sửa</span></span></a>
                </td>
                <td>
                    <a href="javascript:void(0)" class="text-danger" onclick="deleteUser(${i}, this)"><span class = "delete"><i class="fa fa-trash-alt"></i><span class = "text_del"> Xóa</span></span></a>
                </td>
            </tr>
        `
    $("tbody").html(contentHtml);
    }
}

function deleteUser(index,deleteRow){
    // Xóa các hàng theo yêu cầu
    students.splice(index,1);
    if(confirm("Are you sure")){
        $(deleteRow).parent().parent().remove();
    }
    renderContent();
}

function sortStudentbyCol(column){
    // Sắp xệp lại các cột theo trường
    students.sort(function(a,b){
        if(a[column] > b[column]) return 1;
        if(a[column] < b[column]) return -1;
        return 0;
    });
    renderContent();
}

function searchChar(){
    // Hàm search kí tự trong bảng
    var input,inputValue,tr,trContent = "",tbody;
    input = document.getElementById("myInput");
    inputValue = input.value.toUpperCase();
    tbody = document.getElementById("tbody");
    // Sử dụng getElementsByTagName để lấy ra mảng các phần tử
    tr = tbody.getElementsByTagName("tr");
    for(let i=0; i<tr.length; i++){
        // Lấy chuỗi text trong thẻ tr 
        trContent = tr[i].getElementsByTagName("td")[0].textContent.toUpperCase() + tr[i].getElementsByTagName("td")[1].textContent.toUpperCase() + tr[i].getElementsByTagName("td")[2].textContent.toUpperCase() + tr[i].getElementsByTagName("td")[3].textContent.toUpperCase() ;
        if(trContent.indexOf(inputValue) > -1)
            tr[i].style.display = "";
        else tr[i].style.display = "none";
    } 
}

function addUser(){
    
}

$(function () {
    // Note
    renderContent();
})

