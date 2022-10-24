import express, {Express, Router, Request, Response, NextFunction} from 'express'
import axios from 'axios'
const app:Express = express()

app.use('*', (req:Request, res:Response, next: NextFunction)=>{
    // 允许跨域
    res.header('Access-Control-Allow-Origin', '*')

    next()
})

const router = express.Router() // 分模块

app.use('/api', router)


router.get('/list', async (req:Request, res: Response) => {
    const result = await axios.post("https://api.inews.qq.com/newsqa/v1/query/inner/publish/modules/list?modules=localCityNCOVDataList,diseaseh5Shelf")
    res.json({
        // 解构？
        ...result.data.data
    })
})

app.listen(3333, ()=> {
    console.log("success server http://localhost:3333")
})