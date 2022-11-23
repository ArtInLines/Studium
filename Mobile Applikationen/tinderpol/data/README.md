# API

## /data?page=$pageNumber

Retrieve 100 notices. Changing the page-parameter, you can paginate through the data.

### Response:

```js
{
	notices: Notice[],
	max_cursor: Number,
	current_page: Number,
	next_page: Number,
}
```

## /all

Retrieve all Data at once

### Response:

```js
{
	notices: Notice[]
}
```
