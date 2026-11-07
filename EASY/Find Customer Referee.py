import pandas as pd

def find_customer_referee(customer: pd.DataFrame) -> pd.DataFrame:
    customer.fillna(1,inplace=True)
    result = customer[customer['referee_id'] != 2 ][['name']]
    return result
