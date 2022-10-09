type NameList = {
  name: string;
};

export const axios = (url: string): Promise<NameList[]> => {
  return new Promise((resolve) => {
    let xhr: XMLHttpRequest = new XMLHttpRequest();

    xhr.open("GET", url);
    // 不能使用
    xhr.onreadystatechange = () => {
      if (xhr.readyState == 4 && xhr.status == 200) {
        setTimeout(() => {
          resolve(JSON.parse(xhr.responseText));
        }, 200);
      }
      
      xhr.send(null);
    };
  });
};
