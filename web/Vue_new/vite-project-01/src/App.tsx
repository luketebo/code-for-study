import { ref } from "vue";

let v = ref<string>('')

let flag = true;

let Arr = [1, 2, 3, 4]

type Props = {
  title: string
}

const renderDom = (props: Props, ctx: any) => {
  return (
    <div>
      <div>{props.title}</div>
      {
        Arr.map(v=>{
          return (<div onClick={clickTapA.bind(this, ctx)} data-index={v} >{v}</div>)
          // return (<div onClick={clickTap} data-index={v} >{v}</div>)
        })
      }
    </div>
  );
};
const clickTapA = (ctx: any) => {
    ctx.emit('on-click', 123)
}

const clickTap = () => {
  console.log("222")
}

export default renderDom;
