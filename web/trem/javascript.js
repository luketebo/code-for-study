/*
$("#container")
  .find("img")
  .each(function () {
    var img = this;
    if (img.width > 30) {
      img.style.width = "30px";
      img.style.height = "30px";
      //$(img).removeAttr('height');
      
      var aTag = document.createElement('a');
      aTag.href = img.src;
            aTag.target="_blank";
      $(aTag).addClass('bPic')
      .insertAfter(img).append(img)
      .lightBox(options);
     
    }
  }); 
  */
$(".col-md-4 img").css({
  width: "300px",
  height: "200px"
});
