import { onMounted } from "vue";

type Option = {
  el: string;
};

export default function (option: Option): Promise<{ baseUrl: string }> {
  return new Promise((resolve) => {
    onMounted(() => {
      let img: HTMLImageElement = document.querySelector(
        option.el
      ) as HTMLImageElement;
      img.onload = () => {
        resolve({
          baseUrl: base64(img),
        });
      };
    });

    const base64 = (el: HTMLImageElement) => {
      const canvas = document.createElement("canvas");
      const ctx = canvas.getContext("2d");
      canvas.width = el.width;
      canvas.height = el.height;
      ctx?.drawImage(el, 0, 0, canvas.width, canvas.height);
      return canvas.toDataURL("image/jpg");
    };
  });
}
