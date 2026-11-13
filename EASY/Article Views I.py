import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    views = views[(views['author_id'])==(views['viewer_id'])]
    views = views.drop_duplicates(['author_id'],keep='first')
    views = views[['author_id']].rename(columns={'author_id':'id'})
    return views.sort_values(by='id')
