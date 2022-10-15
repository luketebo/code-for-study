import { defineConfig } from "vite";
import vue from "@vitejs/plugin-vue";
import pxtocssViewPort from "postcss-px-to-viewport";

// https://vitejs.dev/config/
export default defineConfig({
  plugins: [vue()],
  css: {
    postcss: {
      plugins: [
        pxtocssViewPort({
          unitToConvert: "px", // 转化的单位
          viewportWidth: 320, // UI 设计稿的宽度
        }),
      ],
    },
  },
});
